#AJG23085 谷口香央
#!/usr/bin/env python
# -*- coding:utf-8 -*-

import calculator

a = 8
b = 10
print(a,"+",b,"=",calculator.add(a,b))
print(a,"-",b,"=",calculator.subtract(a,b))
print(a,"*",b,"=",calculator.multiply(a,b))
try:
    print(a,"/",b,"=",calculator.divide(a,b))
except ZeroDivisionError:
    print("0で割ることはできません。")