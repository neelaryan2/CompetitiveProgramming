#include<bits/stdc++.h>
using namespace std;
const int kMod = 1e9 + 7;
struct ModInt {
	long long n;
	ModInt(long long n = 0) : n(n % kMod) {}
	ModInt operator+(const ModInt& oth) { return n + oth.n; }
	ModInt operator-(const ModInt& oth) { return n - oth.n; }
	ModInt operator*(const ModInt& oth) { return n * oth.n; }
	long long get() { return n < 0 ? n + kMod : n; }
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
	fact.assign(n + 1, 1);
	invfact.assign(n + 1, 1);
	for (int i = 1; i <= n; ++i)
		fact[i] = fact[i - 1] * i;
	invfact[n] = lgpow(fact[n]);
	for (int i = n - 1; i >= 1; --i)
		invfact[i] = invfact[i + 1] * (i + 1);
}
ModInt choose(int n, int k) {
	return fact[n] * invfact[k] * invfact[n - k];
}
void solve() {
	int x, y;
	cin >> x >> y;
	vector<int> cnt;
	for (int i = 2; i * i <= x; i++) {
		if (x % i) continue;
		int c = 0;
		while (x % i == 0) x /= i, c++;
		cnt.emplace_back(c);
	}
	if (x != 1) cnt.emplace_back(1);
	ModInt ans = 1;
	for (int i : cnt) {
		ans = ans * choose(i + y - 1, i);
	}
	ans = ans * lgpow(2, y - 1);
	cout << ans.get() << endl;
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	factorials(1e6 + 1000);
	int t; cin >> t;
	while (t--) solve();
}