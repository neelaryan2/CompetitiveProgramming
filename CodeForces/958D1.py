def gcd(x, y):
    while y:
        x, y = y, x % y
    return x

n = int(input())
cnt = [0 for i in range(20000)]
v = [0 for i in range(n)]
for i in range(n):
    num, den = input().split("/")
    num = eval(num)
    den = eval(den)
    g = gcd(num, den)
    num //= g
    den //= g
    key = num * 100 + den
    v[i] = key
    cnt[key] += 1

for i in range(n):
    print(cnt[v[i]], end=" ")
print()

