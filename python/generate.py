#!/usr/bin/env python
# encoding: utf-8

#########################################
# File Name: generate.py
# Author: yuntao.hyt
# Mail: yuntao.hyt@alibaba-inc.com
# Created Time: 2015-07-16 10:29:50
#########################################

import yaml
import os
import shutil
import urllib

import xml.etree.ElementTree as ET

from Cheetah.Template import Template


url_head = 'http://repo.alibaba-inc.com/nexus/content/groups/b2bnewrepos'


# dependency in old pom
class Lib(object):

    def __init__(self):
        self.groupId = ''
        self.artifactId = ''
        self.version= ''
        self.name = ''
        self.exclusions = []


# get intl base version and other dependency
def getVersion(lst, path):
    os.system('mvn -f ' + path + ' dependency:list > list')
    file = open('list', 'r')
    dep = {}
    for depend in lst:
        dep[depend.groupId + ':' + depend.artifactId] = depend
    for depend in file:
        if depend.find('jar') < 0:
            continue
        try:
            line = depend.split(' ')[4].split(':')
            url = url_head
            for x in line[0].split('.'):
                url = url + '/' + x
            url = url + '/' + line[1] + '/' + line[3]
            if urllib.urlopen(url).getcode() != 200:
                print 'sorry, this may be analyzed manually'
                print depend
                continue
            if dep.has_key(line[0] + ':' + line[1]):
                dep[line[0] + ':' + line[1]].version = line[3]
            else:
                temp = Lib()
                temp.groupId = line[0]
                temp.artifactId = line[1]
                temp.version = line[3]
                dep[line[0] + ':' + line[1]] = temp
        except IndexError:
            print 'sorry, this may be analyzed manually'
            print depend
    file.close()
    return list(dep.values())


# generate new pom
def generatePom(pos, path):
    project = Lib()
    project.groupId = 'com.aliexpress.trade.open'
    project.artifactId = pos + '.' + path
    project.name = pos + '-' + path

    lst = []
    needAnalyze = False

    oldPom = '../' + path + '/pom.xml'

    if os.path.isfile(oldPom):
        xmlDoc = ET.parse(oldPom)
        xmlRoot = xmlDoc.getroot()
        version = xmlRoot.find('{http://maven.apache.org/POM/4.0.0}version').text.split('.')
        dependencies = xmlRoot.find('{http://maven.apache.org/POM/4.0.0}dependencies')
        for dependency in dependencies:
            dep = Lib()
            dep.groupId = dependency.find('{http://maven.apache.org/POM/4.0.0}groupId').text
            dep.artifactId = dependency.find('{http://maven.apache.org/POM/4.0.0}artifactId').text
            dv = dependency.find('{http://maven.apache.org/POM/4.0.0}version')
            de = dependency.find('{http://maven.apache.org/POM/4.0.0}exclusions')
            if dv is not None:
                dep.version = dv.text
            else:
                needAnalyze = True
            if de is not None:
                for el in de:
                    exclusion = Lib()
                    exclusion.groupId = el.find('{http://maven.apache.org/POM/4.0.0}groupId').text
                    exclusion.artifactId = el.find('{http://maven.apache.org/POM/4.0.0}artifactId').text
                    dep.exclusions.append(exclusion)
            lst.append(dep)
        try:
            version[-1] = str(int(version[-1]) + 1)
            project.version = '.'.join(version)
        except ValueError:
            print 'version is ' + version + ', please handle it manully!'
    else:
        print oldPom + ' not exists!'
        return

    lst = getVersion(lst, oldPom)

    mp = {'lib' : project, 'lst' : lst}

    t = Template(file="pom.tmpl", searchList=[mp])

    open(path + '/pom.xml','w').write(str(t))

    print 'generate pom for  ' + project.name + '  success!'


# copy src dir to new lib
def copySrc(path):
    src = '../' + path + '/src'
    dst = path + '/src'
    if os.path.isdir(src):
        if not os.path.isdir(dst):
            shutil.copytree(src, dst)
            print 'copy src to new dir success!'
        else:
            print dst + ' already exists!'
    else:
        print src + ' not exists!'


# cerate new lib dir
def createDir():
    stream = open('generate.yaml', 'r')
    
    trade = yaml.load(stream)['trade']
    
    tp = trade['tp']
    modules = trade['modules']
    
    for path in tp:
        if not os.path.isdir(path):
            os.mkdir(path)
        print '------------------------------------------------------------'
        generatePom('tp', path)
        copySrc(path)
        print '------------------------------------------------------------'
    
    for path in modules:
        if not os.path.isdir(path):
            os.mkdir(path)
        print '------------------------------------------------------------'
        generatePom('modules', path)
        copySrc(path)
        print '------------------------------------------------------------'


if __name__=='__main__':
    createDir()
