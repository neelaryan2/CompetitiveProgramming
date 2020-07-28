const int kMod = 1e6 + 3;
#define all(v) (v).begin(), (v).end()
#define lb lower_bound
struct ModInt {
    long long n;
    ModInt(long long n = 0) : n(n % kMod) {}
    ModInt operator+(const ModInt& oth) { return n + oth.n; }
    ModInt operator-(const ModInt& oth) { return n - oth.n; }
    ModInt operator*(const ModInt& oth) { return n * oth.n; }
    long long get() { return n < 0 ? n + kMod : n; }
    friend ostream& operator<<(ostream& os, ModInt const& a) { return os << ModInt(a.n).get(); }
};
ModInt lgpow(ModInt b, int e = -1) {
    if (b.get() == 0) return 0;
    ModInt r; e = e % (kMod - 1);
    if (e < 0) e += kMod - 1;
    for (r = 1; e; e >>= 1, b = b * b)
        if (e & 1) r = r * b;
    return r;
}
int Solution::findRank(string A) {
    int n = A.size();
    vector<ModInt> fact(n + 1, 1), invfact(n + 1, 1);
    for (int i = 1; i <= n; ++i)
        fact[i] = fact[i - 1] * i;
    invfact[n] = lgpow(fact[n]);
    for (int i = n - 1; i >= 1; --i)
        invfact[i] = invfact[i + 1] * (i + 1);
    char mn = *min_element(all(A));
    char mx = *max_element(all(A));
    int len = mx - mn + 1;
    ModInt ans = 1;
    vector<int> cnt(len, 0);
    for (char c : A) cnt[c - mn]++;
    for (int i = 0; i < n; i++) {
        int small = 0, cur = A[i] - mn;
        ModInt prod = 1;
        for (int j = 0; j < len; j++) {
            if (j < cur) small += cnt[j];
            prod = prod * invfact[cnt[j]];
        }
        prod = prod * small * fact[n - i - 1];
        ans = ans + prod;
        cnt[cur]--;
    }
    return ans.get(); 
}
