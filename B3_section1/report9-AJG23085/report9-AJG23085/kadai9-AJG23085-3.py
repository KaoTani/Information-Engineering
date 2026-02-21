#AJG23085 谷口香央
#!/usr/bin/env python
# -*- coding:utf-8 -*-

try:
    fin = open('data_9_3.txt', 'r')
except FileNotFoundError: 
    print('ファイルが存在しません: data_9_3.txt')
else:
    l = []
    for line in fin: # ファイルから１行ずつ読み込む
        try:
            t = int(line.strip()) # 前後の空白や改行を取り除く
        except ValueError:
            pass
        else:
            l.append(t)
    print(sum(l))
    

        