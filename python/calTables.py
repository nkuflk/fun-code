#!/usr/bin/python
#-*- coding:utf-8 -*-
#########################################
# File Name: calTables.py
# Author: F.L.K
# Mail: nkuflk@gmail.com
# Created Time: 2015-07-16 09:29:50
#########################################

sql = 'update tp_fund_order_%04d set should_pay_logistics_amt_cur="USD" where order_id=%d;'

ids = open('id.csv', 'r')

lst = []
for i in xrange(16):
    lst.append(open('database' + str(i) + '.txt', 'w'))

for id in ids:
    table = int(id) % 10000 % 512
    database = table / 32
    temp = sql % (table, int(id))
    lst[database].write(temp + '\n')

ids.close()
for i in lst:
    i.close()
