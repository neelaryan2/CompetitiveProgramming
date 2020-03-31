#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll inf = 2e18;
const double pi = 3.141592653589793238;
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	vector<ll> vol(n);
	for (int i = 0; i < n; i++) {
		int r, h;
		cin >> r >> h;
		vol[i] = 1LL * r * r * h;
	}
	ll mx = -1;
	map<ll, ll> m; m[0] = 0;
	for (int i = 0; i < n; i++) {
		auto it = m.lower_bound(vol[i]); it--;
		ll curr = max(m[vol[i]], it->se + vol[i]);
		it = m.upper_bound(vol[i]);
		m[vol[i]] = curr;
		while (it != m.end() && it->se < curr)
			m.erase(it), it = m.upper_bound(vol[i]);
		mx = max(mx, curr);
	}
	double ans = 1.0 * pi * mx;
	cout << fixed << setprecision(10) << ans << endl;
}