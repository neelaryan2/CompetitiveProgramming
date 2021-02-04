#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
using pii = pair<int, int>;
const int inf = 1e6;

vector<pii> par;
vector<int> depth, wei;
vector<vector<int>> lca;
vector<vector<pii>> adj
                 ;
void dfs(int v, int p, int id) {
	par[v] = make_pair(p, id);
	for (pii u : adj[v]) {
		if (u.fi == p) continue;
		depth[u.fi] = depth[v] + 1;
		dfs(u.fi, v, u.se);
	}
}
int LCA(int i, int j) {
	int& ans = lca[i][j];
	if (ans != -1) return ans;
	if (i == j) {ans = i; return ans;}
	if (depth[i] > depth[j]) ans = LCA(par[i].fi, j);
	else if (depth[i] < depth[j]) ans = LCA(i, par[j].fi);
	else ans = LCA(par[i].fi, par[j].fi);
	lca[j][i] = ans;
	return ans;
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	adj.resize(n);
	par.resize(n);
	depth.resize(n);
	wei.assign(n - 1, 0);
	lca.assign(n, vector<int>(n, -1));
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		adj[a].emplace_back(make_pair(b, i));
		adj[b].emplace_back(make_pair(a, i));
	}
	depth[0] = 0;
	dfs(0, -1, -1);
	int m; cin >> m;
	vector<pair<pii, int>> q(m);
	for (int i = 0; i < m; i++) {
		int g, a, b;
		cin >> a >> b >> g;
		a--; b--;
		q[i] =  make_pair(make_pair(a, b), g);
		int l = LCA(a, b);
		while (a != l) {
			pii p = par[a];
			wei[p.se] = max(wei[p.se], g);
			a = p.fi;
		}
		while (b != l) {
			pii p = par[b];
			wei[p.se] = max(wei[p.se], g);
			b = p.fi;
		}
	}
	for (auto t : q) {
		int a = t.fi.fi, b = t.fi.se, g = t.se;
		int l = LCA(a, b), mn = inf;
		while (a != l) {
			pii p = par[a];
			mn = min(mn, wei[p.se]);
			a = p.fi;
		}
		while (b != l) {
			pii p = par[b];
			mn = min(mn, wei[p.se]);
			b = p.fi;
		}
		if (mn != g) {
			cout << "-1" << endl;
			return 0;
		}
	}
	for (int i : wei) cout << ((i < 1) ? inf : i) << " ";
	cout << endl;
}