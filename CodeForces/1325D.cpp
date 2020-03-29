#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using piii = pair<pii, int>;
using vs = vector<string>;
#define fi first
#define se second
const ll mod = 998244353;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ll u, v;
	cin >> u >> v;
	ll w = (v - u) / 2;
	if (w < 0 || 2 * w != v - u) {
		cout << -1 << endl;
		return 0;
	}
	if (w & u) {
		cout << 3 << endl;
		cout << u << " " << w << " " << w << endl;
		return 0;
	}
	if (w == 0) {
		if (u == 0) cout << 0 << endl;
		else cout << 1 << endl << u << endl;
		return 0;
	}
	cout << 2 << endl;
	cout << w << " " << v - w << endl;
}