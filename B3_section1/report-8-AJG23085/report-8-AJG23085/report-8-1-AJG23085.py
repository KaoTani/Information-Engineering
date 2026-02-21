#AJG23085 谷口香央
#!/usr/bin/env python
# -*- coding:utf-8 -*-

import re

# ファイル入出力
# 読み込み
fin = open("kadai-8-1-test.txt", 'r')
l = [] # 空のリスト
for line in fin: # ファイルから１行ずつ読み込む
    t = line.strip() # 前後の空白や改行を取り除く
    tw1 = t.split(' ')
    for w in tw1:
        tw2 = re.sub(r'[^a-zA-Z0-9]', '', w)
        if tw2:
            l.append(tw2)

fin.close()

d = {} # 空の辞書型を作る

# 単語を一つずつ辞書に登録する
for w in l: 
    if not w in d: # 辞書に単語がまだ登録されていない場合
        d[w] = 1 # 初期値(１)を入力
    else: # 辞書に単語が既に登録されている場合
        d[w] += 1 # １つ増やす

# 書き込み
fout = open("kadai-8-1-test-out.txt", 'w')
fout.write("＜ファイル＞\n")
fout.write("kadai-8-1-test.txt\n")
# 辞書のキーと値を出力する (ソートあり)
# 降順にソートして表示したければ，関数 Sorted の引数 reverse=True を使う
fout.write('\n')
fout.write("＜単語と出現頻度＞\n")
for k, v in sorted(d.items(), key=lambda x:x[1], reverse=True):
    fout.write("{}: {}\n".format(k, v))
fout.close()