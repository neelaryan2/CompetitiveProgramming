n = int(input())
lst = input().split()
lst = [int(x) for x in lst]
ans = 0
cnt = {}
for i, e in enumerate(lst):
    ans += (2 * i + 1 - n) * e
    cnt[e] = 0

for e in lst:
    if e - 1 in cnt.keys():
        ans -= cnt[e - 1]
    if e + 1 in cnt.keys():
        ans += cnt[e + 1]
    cnt[e] += 1

print(ans)
