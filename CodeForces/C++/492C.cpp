#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define fi first
#define se second

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ll n, r, avg, need = 0;
	cin >> n >> r >> avg;
	vector<pii> ba(n);
	for (int i = 0; i < n; i++) {
		cin >> ba[i].se >> ba[i].fi;
		need += ba[i].se;
	}
	ll ans = 0;
	need = n * avg - need;
	sort(ba.begin(), ba.end());
	for (pii p : ba) {
		if (need <= 0) break;
		ll t = min(need, r - p.se);
		ans += t * p.fi; need -= t;
	}
	cout << ans << endl;
}