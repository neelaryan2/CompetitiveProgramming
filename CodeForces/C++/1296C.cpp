#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define fi first
#define se second
const int inf = 1e9;

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	pii p = make_pair(0, 0);
	map<pii, int> path;
	path[p] = -1;
	pii ans = make_pair(inf, inf);
	int mn = inf;
	for (int i = 0; i < n; i++) {
		char c = s[i];
		if (c == 'L') p.fi--;
		else if (c == 'R') p.fi++;
		else if (c == 'U') p.se++;
		else if (c == 'D') p.se--;
		auto it = path.find(p);
		if (it != path.end() && i - it->se < mn) {
			mn = i - it->se;
			ans.se = i + 1;
			ans.fi = it->se + 2;
		}
		path[p] = i;
	}
	if (ans.fi == inf) {cout << -1 << endl; return;}
	cout << ans.fi << " " << ans.se << endl;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int q; cin >> q;
	while (q--) solve();
}