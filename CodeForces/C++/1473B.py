t = int(input())


def gcd(a, b):
    if b == 0: return a
    return gcd(b, a % b)


for i in range(t):
    s = input()
    t = input()
    n, m = len(s), len(t)
    l = (n * m) // gcd(n, m)
    p1 = s * (l // n)
    p2 = t * (l // m)
    if p1 == p2:
        print(p1)
    else:
        print(-1)
