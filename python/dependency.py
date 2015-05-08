#!/usr/bin/python
#-*- coding:utf-8 -*-
#########################################
# File Name: dependency.py
# Author: F.L.K
# Mail: nkuflk@gmail.com
#########################################

def main():
    online = open('online', 'r')
    for line in online:
        print line,
    online.close()

if __name__ == '__main__':
    main()
