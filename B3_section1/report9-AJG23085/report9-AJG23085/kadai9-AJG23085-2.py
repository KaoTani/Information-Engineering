#AJG23085 谷口香央
#!/usr/bin/env python
# -*- coding:utf-8 -*-

a = 3
b = 5

class Rectangle(object):
    def __init__(self, width, height):
        self.width = width
        self.height = height
    def area(self):
        return self.width*self.height

rectangle = Rectangle(a, b)
print("width:", rectangle.width)
print("height:", rectangle.height)
print("->area:", rectangle.area())