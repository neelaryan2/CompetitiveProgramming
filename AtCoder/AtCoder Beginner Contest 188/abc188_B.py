n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

ret = 0
for i in range(n):
    ret += a[i] * b[i]

if ret == 0:
    print("Yes")
else:
    print("No")
