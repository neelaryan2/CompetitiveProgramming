int Solution::uniquePaths(int A, int B) {
    A--, B--;
    if (A > B) swap(A, B);
    int num = 1, den = 1;
    for (int i = A + B; A--; i--) {
        num *= i, den *= i - B;
        int g = __gcd(num, den);
        num /= g, den /= g;
    }
    return num;
}
