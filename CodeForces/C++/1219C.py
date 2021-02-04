def main():
    L = int(input())
    s = input()
    n = len(s)

    q = 1 + n // L
    base = s[:L]

    if (n % L != 0) or (L > n) or (base == '9' * L):
        print(('1' + '0' * (L - 1)) * q)
        return

    q -= 1
    for i in range(1, q):
        cur = s[L * i:L * (i + 1)]
        if cur > base:
            break
        if cur < base:
            print(base * q)
            return

    carry = 1
    ret = ''
    for i in range(L - 1, -1, -1):
        cur = int(base[i]) + carry
        if cur == 10:
            cur = 0
            carry = 1
        else:
            carry = 0
        ret += str(cur)
    print(ret[::-1] * q)


main()