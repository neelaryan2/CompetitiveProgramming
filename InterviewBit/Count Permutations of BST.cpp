using ll = long long;
const int kMod = 1e9 + 7;
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
vector<ModInt> fact, invfact;
void factorials(int n) {
    if (fact.size() > 1) return;
	fact.resize(n + 1, 1);
	invfact.resize(n + 1, 1);
	for (int i = 1; i <= n; ++i)
		fact[i] = fact[i - 1] * i;
	invfact[n] = lgpow(fact[n]);
	for (int i = n - 1; i >= 1; --i)
		invfact[i] = invfact[i + 1] * (i + 1);
}
ModInt choose(int n, int k) {
	return fact[n] * invfact[k] * invfact[n - k];
}
using vi = vector<int>;
const int N = 105;
vector<vi> dp(N, vi(N, -1));
ModInt solve(int n, int h) {
    if (n <= 1) return (h == 0);
    if (dp[n][h] != -1) return dp[n][h];
    ModInt ans = 0;
    for (int i = 0; i < n; i++) {
        ModInt res = 0;
        for (int j = 0; j < h - 1; j++) {
            res = res + solve(i, j) * solve(n - i - 1, h - 1);
            res = res + solve(n - i - 1, j) * solve(i, h - 1);
        }
        res = res + solve(i, h - 1) * solve(n - i - 1, h - 1);
        ans = ans + choose(n - 1, i) * res;
    }
    return dp[n][h] = ans.get();
}
int Solution::cntPermBST(int n, int h) {
    factorials(N);
    ModInt ans = solve(n, h);
    return ans.get();
}
