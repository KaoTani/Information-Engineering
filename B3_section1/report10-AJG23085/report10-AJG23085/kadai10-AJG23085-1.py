#AJG23085 谷口香央
#!/usr/bin/env python
# -*- coding:utf-8 -*-

import re

with open('genome.txt', 'r') as f1:
    data = f1.read()

pattern = r'AGC'
matchedList = re.findall(pattern, data)
if matchedList:
    print("AGC:", len(matchedList))