int Solution::trailingZeroes(int A) {
    int ans = 0;
    for (int i = 5; i <= A; i *= 5)
        ans += A / i;
    return ans;
}
