#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
const int kMod = 1e9 + 7;
const ll inv6 = 166666668;
struct ModInt {
	long long n;
	ModInt(long long n = 0) : n(n % kMod) {}
	ModInt operator+(const ModInt& oth) { return n + oth.n; }
	ModInt operator-(const ModInt& oth) { return n - oth.n; }
	ModInt operator*(const ModInt& oth) { return n * oth.n; }
	long long get() { return n < 0 ? n + kMod : n; }
};
ModInt sumsqr(ll n) {
	ModInt ans = n;
	ans = ans * (n + 1);
	ans = ans * (2 * n + 1);
	ans = ans * inv6;
	return ans;
}
void solve(ll n) {
	ModInt ans = n;
	ll N = cbrtl(n), tmp, j, k;
	vector<bool> vis(N + 1, false);
	vis[0] = vis[1] = true;
	ModInt sqrN = sumsqr(N);
	for (ll i = 1; i <= N; i++) {
		ld up = ((ld)n * 1.0) / i;
		tmp = sqrtl(up);
		if (tmp > N)
			ans = ans + sumsqr(tmp) - sqrN;
		if (vis[i]) continue;
		j = 1, k = 1;
		while (1) {
			if ((ld)j > up) break;
			else j *= i, k *= i;
			if ((ld)j > up) break;
			else j *= i;
			if (k > N) break;
			if (j <= N) vis[j] = true;
			tmp = n / j;
			ans = ans + tmp * j;
		}
		j = i;
		while (1) {
			if ((ld)j > up) break;
			else j *= i;
			if ((ld)j > up) break;
			else j *= i;
			if (j <= N) vis[j] = true;
			tmp = n / j;
			ans = ans + tmp * j;
		}
	}
	cout << ans.get() << endl;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int t; cin >> t;
	while (t--) {
		ll n; cin >> n;
		solve(n);
	}
}