vector<int> Solution::getRow(int n) {
    vector<int> ans(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        int p = ans[i - 1];
        int a = i, b = n + 1;
        int g = __gcd(a, b);
        a /= g, b /= g;
        ans[i] = (p / a) * b - p;
    }
    return ans;
}
