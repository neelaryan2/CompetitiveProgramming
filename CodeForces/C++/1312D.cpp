#include <bits/stdc++.h>
using namespace std;

const int kMod = 998244353;
struct ModInt {
	long long n;
	ModInt(long long n = 0) : n(n % kMod) {}
	ModInt operator+(const ModInt& oth) { return n + oth.n; }
	ModInt operator-(const ModInt& oth) { return n - oth.n; }
	ModInt operator*(const ModInt& oth) { return n * oth.n; }
	long long get() { return n < 0 ? n + kMod : n; }
};
ModInt lgpow(ModInt b, int e = -1) {
	ModInt r; e = e % (kMod - 1);
	if (e < 0) e += kMod - 1;
	for (r = 1; e; e >>= 1, b = b * b)
		if (e & 1) r = r * b;
	return r;
}
vector<ModInt> fact, invfact;
void factorials(int n) {
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
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m; cin >> n >> m;
	factorials(m);
	ModInt ans = lgpow(2, n - 3);
	ans = ans * choose(m, n - 1) * (n - 2);
	cout << ans.get() << endl;
	return 0;
}