#AJG23085 谷口香央
#!/usr/bin/env python
# -*- coding:utf-8 -*-

import pickle

grades = {
 "Alice": [85, 92, 78],
 "Bob": [79, 81, 90],
 "Charlie": [95, 87, 85]
}
with open('kadai10-AJG23085-3.pkl', 'wb') as fout:
    pickle.dump(grades, fout)

b = {}
with open('kadai10-AJG23085-3.pkl', 'rb') as fin: 
    b = pickle.load(fin)

for k,v in b.items():
    print(k,':',v)