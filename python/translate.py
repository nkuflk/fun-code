# -*- coding: utf-8 -*-

import urllib2
import json

url = 'http://fanyi.youdao.com/openapi.do?keyfrom=flkclub&key=770083173&type=data&doctype=json&version=1.1&q='

text = raw_input('input: ')

url += text

req = urllib2.urlopen(url)

ans = req.read()

json_ans = json.loads(ans)

if json_ans.has_key('basic'):
    if json_ans['basic'].has_key('explains'):
        temp = "".join(json_ans['basic']['explains'])
        print temp

if json_ans['errorCode']==0:
    print json_ans['translation'][0]
