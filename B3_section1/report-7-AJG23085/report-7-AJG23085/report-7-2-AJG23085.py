#AJG23085 谷口香央
#!/usr/bin/env python
# -*- coding:utf-8 -*-

import sys

a = int(sys.argv[1])
b = int(sys.argv[2])
c = int(sys.argv[3])
print('2次方程式 ax^2+bx+c=0 の解がどのようになるか判別します.')
print('')

print('a={}, b={}, c={}'.format(a,b,c))
print('')
d = b*b-4*a*c
print('判別式 b^2-4ac = {}'.format(d))
if d>0:
    print('2実数解')
elif d==0:
    print('重解')
else:
    print('虚数解')