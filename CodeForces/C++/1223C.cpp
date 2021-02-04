#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 2;
ll n, x, a, y, b, l, k;
int p[maxn];
bool possible(int t) {
	ll ans = 0, i = 0, lc = t / l, la = t / a - lc, lb = t / b - lc;
	while (lc--) ans += p[i++] * (x + y);
	while (la--) ans += p[i++] * (x);
	while (lb--) ans += p[i++] * (y);
	return ans >= k;
}
inline void solve() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i], p[i] /= 100;
	cin >> x >> a >> y >> b >> k;
	sort(p, p + n); reverse(p, p + n);
	if (x < y) swap(a, b), swap(x, y);
	l = ((a * b) / __gcd(a, b));
	int lo = -1, hi = n, mid;
	while (lo < hi - 1) {
		mid = lo + (hi - lo) / 2;
		if (possible(mid)) hi = mid;
		else lo = mid;
	}
	if (!possible(n)) cout << "-1\n";
	else cout << hi << "\n";
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int q;
	cin >> q;
	while (q--)
		solve();
}