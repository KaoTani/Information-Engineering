#AJG23085 谷口香央

import sys

a = int(sys.argv[1])
b = int(sys.argv[2])
c = int(sys.argv[3])

print('点数：', a, '点 ', b, '点 ', c, '点')
ave = (a+b+c)/3
print('平均点： {:3.1f}点'.format(ave))
if a>b:
    max=a
    min=b
else:
    max=b
    min=a
if c>max:
    max=c
if c<min:
    min=c
print('最高点：', max, '点')
print('最低点：', min, '点')