import json 
import os

code_files = os.listdir('../Codeforces/')

codes = []
for p in code_files:
    if '_' in p: continue
    name = p.split('.')[0]
    if name[-1] in '0123456789':
        name = name[:-1]
    codes.append(name)

with open('neelaryan.json',) as fp: 
    data = json.load(fp)['result']

names = []
extra = []
for sub in data:
    p = sub['problem']
    name = str(p['contestId']) + p['index']
    if name[-1] in '0123456789':
        name = name[:-1]
    if name not in codes:
        extra.append(name)
    names.append(name)

extra = sorted(list(set(extra)))
print(extra)

unsub = sorted([code for code in codes if code not in names])

print(len(unsub))
print(unsub)