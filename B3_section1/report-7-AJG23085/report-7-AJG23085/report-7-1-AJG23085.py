#AJG23085 谷口香央
#!/usr/bin/env python
# -*- coding:utf-8 -*-

print('学生10名の課題の最高点,最低点,平均点を表示します.')
print('')
a=[74, 50, 84, 92, 63, 32, 49, 28, 17, 90]
print('最高点: {}点'.format(max(a)))
print('最低点: {}点'.format(min(a)))
b = sum(a)/len(a)
print('平均点： {:3.2f} 点'.format(b))
print('')

print('合否')
for i in range(len(a)):
    if a[i] >= 60:
        print("{}: {}点 合格".format(i+1, a[i]))
    else:
        print("{}: {}点 不合格".format(i+1, a[i]))
