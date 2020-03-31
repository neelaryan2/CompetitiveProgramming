#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
using pii = pair<int, int>;
using ll = long long;
const int inf = 4e5 + 5;
const int kMod = 998244353;
struct ModInt {
	long long n;
	ModInt(long long n = 0) : n(n % kMod) {}
	ModInt operator+(const ModInt& oth) { return n + oth.n; }
	ModInt operator-(const ModInt& oth) { return n - oth.n; }
	ModInt operator*(const ModInt& oth) { return n * oth.n; }
	long long get() { return n < 0 ? n + kMod : n; }
};
ModInt lgpow(ModInt b, ll e = -1) {
	if (b.get() == 0) return 0;
	ModInt r; e = e % (kMod - 1);
	if (e < 0) e += kMod - 1;
	for (r = 1; e; e >>= 1, b = b * b)
		if (e & 1) r = r * b;
	return r;
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, m, l, r;
	cin >> n >> m >> l >> r;
	ll x = r - l + 1, y = 1LL * n * m;
	ModInt ans = lgpow(x, y);
	if (y & 1) {
		cout << ans.get() << endl;
		return 0;
	}
	if (x & 1) ans = ans + 1;
	ans = ans * lgpow(2);
	cout << ans.get() << endl;
}