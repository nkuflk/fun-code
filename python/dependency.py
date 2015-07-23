#!/usr/bin/env python
# encoding: utf-8

#########################################
# File Name: dependency.py
# Author: yuntao.hyt
# Mail: yuntao.hyt@alibaba-inc.com
# Created Time: 2015-06-26 17:29:50
#########################################

import sys
import os
import xml.etree.ElementTree as ET
import urllib

dependencyList = []
used = {}
url_head = 'http://repo.alibaba-inc.com/nexus/content/groups/b2bnewrepos'


# dependency class
class Item(object):

    def __init__(self, groupId, artifactId, version):
        self.groupId = groupId
        self.artifactId = artifactId
        self.version = version


# find pom which packaging is war
# mvn dependency:list just can analyze to war level
def findUsefulPom(path):
    files = []
    for root, name, file in os.walk(path):
        if 'pom.xml' in file:
            files.append(os.path.join(root, 'pom.xml'))
    res = []
    for f in files:
        xmlDoc = ET.parse(f)
        xmlRoot = xmlDoc.getroot()
        value = xmlRoot.find('{http://maven.apache.org/POM/4.0.0}packaging').text
        if value in ['war', 'ali-war']:
            res.append(f)
    return res


# get dependency and request maven repo to check exist
def analyzePom(pom):
    print 'analyzing ' + pom
    file = open('list', 'r')
    pomLen = 0
    for depend in file:
        if depend.find('jar') < 0:
            continue
        pomLen += 1
    file.seek(0)
    curLen = 0
    for depend in file:
        if depend.find('jar') < 0:
            continue
        curLen += 1
        line = depend.split(' ')[4].split(':')
        url = url_head
        for x in line[0].split('.'):
            url = url + '/' + x
        url = url + '/' + line[1] + '/' + line[3]
        if used.has_key('url'):
            continue
        used[url] = 1
        if urllib.urlopen(url).getcode() != 200:
            print '\nsorry, this may be analyzed manually'
            print depend
        else:
            item = Item(line[0], line[1], line[3])
            dependencyList.append(item)
        x = curLen * 100.0 / pomLen
        sys.stdout.write('\ranalyzign %6.2f' % x + '%')
        sys.stdout.flush()
    file.close()
    print '\nanalyze ' + pom + ' success!'


def getDependency(pom):
    for file in pom:
        os.system('mvn -f ' + file + ' dependency:list > list')
        analyzePom(file)


# generate dependencyManagement
def writeDependency():
    file = open('dependency.xml', 'w')
    file.write('<dependencyManagement>\n\t<dependencies>\n')
    for item in dependencyList:
        file.write('\t\t<dependency>\n\t\t\t<groupId>')
        file.write(item.groupId)
        file.write('</groupId>\n\t\t\t<artifactId>')
        file.write(item.artifactId)
        file.write('</artifactId>\n\t\t\t<version>')
        file.write(item.version)
        file.write('</version>\n\t\t</dependency>\n')
    file.write('\t</dependencies>\n</dependencyManagement>\n')
    file.close()


def handle(path):
    print '-------------------------------------'
    print 'getting useful pom.xml...'
    file = findUsefulPom(path)
    print 'get pom.xml success!'
    for line in file:
        print line
    print '-------------------------------------'
    print 'generating dependencies...'
    getDependency(file)
    print 'generate dependencies success!'
    print '-------------------------------------'
    print 'writng dependency.xml...'
    writeDependency()
    print 'write to dependency.xml success!'
    print '-------------------------------------'


if __name__=='__main__':
    try:
        path = sys.argv[1]
        if os.path.isdir(path):
            handle(path)
        else:
            print '"' + path + '" is not a dir'
    except IndexError:
        print 'usage: python dependency.py [path]'
