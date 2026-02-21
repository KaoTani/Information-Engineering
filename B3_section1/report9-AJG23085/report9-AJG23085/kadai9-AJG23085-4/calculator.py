#AJG23085 谷口香央
#!/usr/bin/env python
# -*- coding:utf-8 -*-

def add(a, b):
    return a+b

def subtract(a, b):
    return a-b

def multiply(a, b):
    return a*b

def divide(a, b):
    if b==0:
        raise  ZeroDivisionError
    else:
        return a/b