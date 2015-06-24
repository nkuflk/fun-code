#!/usr/bin/env python
# encoding: utf-8

import urllib

url_head = 'http://repo.alibaba-inc.com/nexus/content/groups/b2bnewrepos'

file = open('a', 'r')

used = []

dep = open('pom.xml', 'w')


def write(group, arti, ver):
    dep.write('<dependency>\n')
    dep.write('\t<groupId>')
    dep.write(group)
    dep.write('</groupId>\n')
    dep.write('\t<artifactId>')
    dep.write(arti)
    dep.write('</artifactId>\n')
    dep.write('\t<version>')
    dep.write(ver)
    dep.write('</version>\n')
    dep.write('</dependency>\n')

for depend in file:
    depend = depend.strip()
    line = depend.split(' ')
    for x in line:
        if x.count(':')>1:
            line = x
    line = line.split(':')
    if len(line)>3:
        url = url_head
        for x in line[0].split('.'):
            url = url + '/' + x
        url = url + '/' + line[1] + '/' + line[3]
        if url in used:
            continue
        used.append(url)
        if urllib.urlopen(url).getcode()!=200:
            print url
            print line
            print depend
        else:
            write(line[0], line[1], line[3])
    else:
        print line

file.close()
dep.close()
