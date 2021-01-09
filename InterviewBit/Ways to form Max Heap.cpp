const int mod = 1e9 + 7;
int mul(int a, int b) { return (1LL * a * b) % mod; }
int pow(int n, int k = mod - 2) {
    if (n == 0) return 0;
    int r = 1;
    for (; k; k >>= 1) {
        if (k & 1) r = mul(r, n);
        n = mul(n, n);
    }
    return r;
}
vector<int> fact, invfact, logs, dp;
void pre(int n) {
    if (!fact.empty()) return;
    fact.resize(n);
    invfact.resize(n);
    logs.resize(n);
    dp.assign(n, -1);
    fact[0] = 1;
    for (int i = 1; i < n; i++)
        fact[i] = mul(i, fact[i - 1]);
    invfact[n - 1] = pow(fact[n - 1]);
    for (int i = n - 2; i >= 0; i--)
        invfact[i] = mul(i + 1, invfact[i + 1]);
    logs[0] = logs[1] = 0;
    for (int i = 2; i < n; i++)
        logs[i] = logs[i / 2] + 1;
}
int choose(int n, int k) {
    if (n < 0 || k < 0 || k > n) return 0;
    int res = mul(fact[n], mul(invfact[k], invfact[n - k]));
    return res;
}
int get(int n) {
    int h = logs[n];
    int num = (1 << (h - 1));
    int act = n - (1 << h) + 1;
    if (act <= num) return n - num;
    return n - act;
}
int solver(int n) {
    if (n <= 0) return (n == 0);
    if (dp[n] != -1) return dp[n];
    int l = get(n);
    int& res = dp[n];
    res = mul(choose(n - 1, l), mul(solver(l), solver(n - l - 1)));
    return res;
}
int Solution::solve(int A) {
    pre(1e5);
    return solver(A);
}
