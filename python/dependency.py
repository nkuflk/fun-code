#!/usr/bin/python
#-*- coding:utf-8 -*-
#########################################
# File Name: dependency.py
# Author: F.L.K
# Mail: nkuflk@gmail.com
#########################################

import re
import urllib

split_reg = '-'
url_head = 'http://repo.alibaba-inc.com/nexus/content/groups/b2brepository/'

def get_name(name):
	return name[0 : len(name)-5]

def write(group, arti, ver, f):
	f.write('<dependency>\n')
	f.write('<groupId>')
	f.write(group)
	f.write('</groupId>\n')
	f.write('<artifactId>')
	temp = ''
	if type(arti) == str:
		temp = arti
	else:
		for ar in arti:
			temp = temp + ar + '-'
		temp = temp[0 : -1]
	f.write(temp)
	f.write('</artifactId>\n')
	f.write('<version>')
	temp = ''
	if type(ver) == str:
		temp = ver 
	else:
		for v in ver:
			temp = temp + v + '-'
		temp = temp[0 : -1]
	f.write(temp)
	f.write('</version>\n')
	f.write('</dependency>\n')

def test_url(name, f):
	res = name.split(split_reg)
	url = url_head
	group_id = ''
	if res[0] == 'commons':
		url = url + res[0] + '-' + res[1] + '/'
		group_id = res[0] + '-' + res[1]
		del res[1]
	else:
		group_res = res[0].split('.')
		group_id = res[0]
		for group in group_res:
			url = url + group + '/'
	if len(res) == 3:
		url = url + res[1] + '/' + res[2]
		if urllib.urlopen(url).getcode() != 200:
			print name
		else:
			write(group_id, res[1], res[2], f)
	else:
		if re.match(r'^[0-9\.]+$', res[-2]) and re.match(r'^[0-9a-zA-Z]+$', res[-1]):
			for art in res[1 : -2]:
				url = url + art + '-'
			url = url[0 : -1] + '/' +  res[-2] + '-' + res[-1]
			if urllib.urlopen(url).getcode() != 200:
				print name
			else:
				write(group_id, res[1 : -2], res[-2 :], f)
		else:
			for art in res[1 : -1]:
				url = url + art + '-'
			url = url[0 : -1] + '/' +  res[-1]
			if urllib.urlopen(url).getcode() != 200:
				print name
			else:
				write(group_id, res[1 : -1], res[-1], f)

def main():
	online = open('online', 'r')
	dependency = open('dependency.xml', 'w')
	for line in online:
		line = get_name(line)
		has = test_url(line, dependency)
	online.close()
	dependency.close()

if __name__ == '__main__':
    main()
