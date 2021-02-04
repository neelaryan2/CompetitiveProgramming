me = input()
n = int(input())
cnt = {}
for i in range(n):
    inp = input().split()
    a, b, act = inp[0], inp[-2][:-2], inp[1]
    if a not in cnt.keys(): cnt[a] = 0
    if b not in cnt.keys(): cnt[b] = 0
    if a != me and b != me: continue
    if act == 'posted': sc = 15
    elif act == 'commented': sc = 10
    elif act == 'likes': sc = 5
    cnt[a] += sc
    cnt[b] += sc

lst = sorted(list(cnt.keys()), key = lambda x : (-cnt[x], x))
for name in lst:
    if name == me: continue
    print(name)
