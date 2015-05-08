#!/usr/bin/python
#-*- coding:utf-8 -*-
#########################################
# File Name: iconv.py
# Author: F.L.K
# Mail: nkuflk@gmail.com
# Created Time: 2015-04-28 13:43:52
#########################################

import os
import sys

def convert(filename, in_enc="GBK", out_enc="UTF-8"):
	fp = open(filename, 'r')
	content = fp.read()
	fp.close()
	try:
		new_content = content.decode(in_enc).encode(out_enc)
		fp = open(filename, 'w')
		fp.write(new_content)
		fp.close()
	except:
		print "error..."

def explore(dir):
	for root, dirs, files in os.walk(dir):
		for file in files:
			path = os.path.join(root, file)
			print "convert "
			print path
			convert(path)
			print "done"
			print ""

def main(): 
	if len(sys.argv) > 1:
		path = sys.argv[1]
	if os.path.isdir(path):
		explore(path)

if __name__ == "__main__":
	main()
