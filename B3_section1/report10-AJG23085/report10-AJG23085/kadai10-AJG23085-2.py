#AJG23085 谷口香央
#!/usr/bin/env python
# -*- coding:utf-8 -*-

import re

l = []
l1 = []
with open('file_list.txt', 'r') as f1, open('kadai10-AJG23085-2.txt', 'w') as f2:
    for line in f1: # ファイルから１行ずつ読み込む
        t = line.strip() # 前後の空白や改行を取り除く
        l.append(t)
    
    ptn1 = r'.txt'
    ptn2 = r'.TXT'
    for w in l:
        matchOB1 = re.search(ptn1, w)
        matchOB2 = re.search(ptn2, w)
        if matchOB1:
            f2.write(w.replace(ptn1, '.md'))
        elif matchOB2:
            f2.write(w.replace(ptn2, '.md'))
        else:
            f2.write(w)
        f2.write('\n')