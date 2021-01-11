def main():
    n = int(input())
    a = list(map(int, input().split()))
    l = len(a) // 2
    m1 = max(a[:l])
    m2 = max(a[l:])
    if m1 > m2:
        ans = a.index(m2)
    else:
        ans = a.index(m1)
    print(ans + 1)


main()