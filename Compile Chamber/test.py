x, y = input().split()
x = int(x)
y = int(y)
if x < y:
    x, y = y, x
if y + 3 > x:
    print("Yes")
else:
    print("No")
