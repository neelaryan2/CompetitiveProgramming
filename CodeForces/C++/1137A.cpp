#include<bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()
#define lb lower_bound
#define sz(v) (int)(v).size()

vector<vector<int>> g, r, c;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	g.resize(n);
	r.resize(n);
	c.resize(m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int a; cin >> a;
			g[i].emplace_back(a);
			r[i].emplace_back(a);
			c[j].emplace_back(a);
		}
	}
	for (int i = 0; i < n; i++) {
		sort(all(r[i]));
		auto it = unique(all(r[i]));
		r[i].resize(distance(r[i].begin(), it));
	}
	for (int i = 0; i < m; i++) {
		sort(all(c[i]));
		auto it = unique(all(c[i]));
		c[i].resize(distance(c[i].begin(), it));
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int ir, ic, curr = g[i][j];
			ir = lb(all(r[i]), curr) - r[i].begin();
			ic = lb(all(c[j]), curr) - c[j].begin();
			curr = max(ir, ic) + max(sz(r[i]) - ir, sz(c[j]) - ic);
			cout << curr << " ";
		}
		cout << "\n";
	}
}