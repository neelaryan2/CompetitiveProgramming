#include<bits/stdc++.h>
using namespace std;
using pii = pair<pair<int, int>, pair<int, int>>;
#define fi first
#define se second
const int inf = 1e5 + 5;

int rt;
vector<int> cnt(inf, 0), grt(inf, 0), siz, pos, col;
vector<vector<int>> adj;
int T = 0;
void dfs(int v, int p = -1) {
	pos[v] = T++;
	for (int u : adj[v]) {
		if (u == p) continue;
		dfs(u, v);
		siz[v] += siz[u];
	}
}
bool cmp(pii a, pii b) {
	if (a.fi.fi / rt != b.fi.fi / rt) return a.fi.fi / rt < b.fi.fi / rt;
	else return a.fi.se < b.fi.se;
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	rt = sqrt(n);
	adj.resize(n);
	siz.assign(n, 1);
	pos.resize(n);
	col.resize(n);
	vector<int> tmp(n);
	for (int i = 0; i < n; i++)
		cin >> tmp[i];
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	dfs(0);
	for (int i = 0; i < n; i++)
		col[pos[i]] = tmp[i];
	vector<pii> q(m);
	vector<int> ans(m);
	for (int i = 0; i < m; i++) {
		int v, k; cin >> v >> k; v--;
		q[i] = {{pos[v], pos[v] + siz[v] - 1}, {k, i}};
	}
	sort(q.begin(), q.end(), cmp);
	int L = 0, R = -1;
	for (pii p : q) {
		int l = p.fi.fi, r = p.fi.se;
		while (L < l) grt[cnt[col[L++]]--]--;
		while (L > l) grt[++cnt[col[--L]]]++;
		while (R < r) grt[++cnt[col[++R]]]++;
		while (R > r) grt[cnt[col[R--]]--]--;
		ans[p.se.se] = grt[p.se.fi];
	}
	for (int i : ans) cout << i << endl;
}