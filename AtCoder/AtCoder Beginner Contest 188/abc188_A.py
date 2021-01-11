x, y = list(map(int, input().split()))

if x < y:
    x, y = y, x
if y + 3 > x:
    print("Yes")
else:
    print("No")
