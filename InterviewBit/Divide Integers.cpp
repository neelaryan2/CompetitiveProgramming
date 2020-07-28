using uint = unsigned int;
using ll = long long;
uint bdiv(uint dividend, uint divisor) {
    uint quotient = 0, remainder = 0;
    if (divisor == 0) return -1;
    for (int i = 31 ; i >= 0 ; i--) {
        quotient <<= 1, remainder <<= 1;
        remainder |= (dividend >> i) & 1;
        if (remainder >= divisor) {
            remainder -= divisor;
            quotient |= 1;
        }
    }
    return quotient;
}
int Solution::divide(int A, int B) {
    ll a = A, b = B, sgn = 1;
    if (a < 0) a = -a, sgn *= -1;
    if (b < 0) b = -b, sgn *= -1;
    if (b == 0) return INT_MAX;
    uint ans = bdiv(a, b);
    sgn *= ans;
    if (sgn < INT_MIN || sgn > INT_MAX) return INT_MAX;
    return sgn;
}
