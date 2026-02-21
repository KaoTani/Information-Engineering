#AJG23085 谷口香央
#!/usr/bin/env python
# -*- coding:utf-8 -*-

import copy

# ファイル入出力
# 読み込み
fin = open("kadai-8-2-testdata.csv", 'r')
l = [] # 空の辞書
for line in fin: # ファイルから１行ずつ読み込む
    t = line.strip() # 前後の空白や改行を取り除く
    tw = t.split(',')
    l.append(tw)

fin.close()

s = []
s1 = []
ave = []
M = []
M_num = []
m = []
m_num = []
s = copy.deepcopy(l)

for i in range(len(s)):
    s[i].pop(0)
    s[i].pop(0)

s1 = [[int(num) for num in sublist] for sublist in s]
for i in range(len(s1[0])):
    kadai = []
    for j in range(len(s1)):
        kadai.append(s1[j][i])
    ave.append(sum(kadai)/len(s1))
    M.append(max(kadai))
    M_num.append(kadai.index(max(kadai)))
    m.append(min(kadai))
    m_num.append(kadai.index(min(kadai)))




# 書き込み
fout = open("kadai-8-2-testdata-out.txt", 'w')
fout.write("学生の課題の最高点，最低点，平均点，各課題の合否を表示します.\n\n")
fout.write("学生の人数: {} 名\n".format(len(l)))
fout.write("課題: {} 題\n\n".format(len(s1[0])))
fout.write("＜課題の平均点，最高点，最低点＞\n\n")
for i in range(len(s1[0])):
    fout.write("課題 {}\n".format(l[i][0]))
    fout.write("平均点: {:3.2f}点\n".format(ave[i]))
    fout.write("最高点: {} {}点\n".format(l[M_num[i]][1],M[i]))
    fout.write("最低点: {} {}点\n".format(l[m_num[i]][1],m[i]))
    fout.write("\n")
fout.write("＜各課題合否＞\n\n")
for i in range(len(s1[0])):
    fout.write("＜課題 {}＞\n".format(l[i][0]))
    for j in range(len(l)):
        fout.write("{}: {} {}点".format(l[j][0],l[j][1],l[j][i+2]))
        if s1[j][i] >= 60:
            fout.write(" 合格\n")
        else:
            fout.write(" 不合格\n")
    fout.write("\n")
        
fout.close()