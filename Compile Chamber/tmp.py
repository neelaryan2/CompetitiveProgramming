import json
import os
import requests
import json

code_dir = "../Codeforces/"
handle = "neelaryan"

code_files = os.listdir(code_dir)

url = f"https://codeforces.com/api/user.status?handle={handle}&from=1&count=10000"
data = requests.get(url).json()

with open(f"{handle}.json", "w+") as fp:
    json.dump(data, fp)

data = data["result"]

codes = []
for p in code_files:
    file = os.path.join(code_dir, p)
    if not os.path.isfile(file):
        continue
    if "_" in p:
        continue
    name = p.split(".")[0]
    if name[-1] in "0123456789":
        name = name[:-1]
    codes.append(name)


names = []
extra = []
for sub in data:
    p = sub["problem"]
    name = str(p["contestId"]) + p["index"]
    if name[-1] in "0123456789":
        name = name[:-1]
    if name not in codes:
        extra.append(name)
    names.append(name)

extra = sorted(list(set(extra)))
print(extra)

unsub = sorted([code for code in codes if code not in names])

print(len(unsub))
print(unsub)