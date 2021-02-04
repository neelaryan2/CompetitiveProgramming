#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using piii = pair<pii, int>;
using vs = vector<string>;
#define fi first
#define se second
const ll mod = 998244353;

vector<int> siz, par, rnk;
vector<vector<int>> adj;
vector<set<int>> nadj;
int comp;

inline void init(int n) {
	par.assign(n, -1);
	rnk.assign(n, 1);
	siz.assign(n, 1);
	nadj.resize(n);
	adj.resize(n);
}
inline int root(int a) {
	if (par[a] == -1) par[a] = a;
	int _a = a;
	while (a != par[a]) a = par[a];
	par[_a] = a;
	return a;
}
inline void add(int a, int b) {
	a = root(a); b = root(b);
	if (a == b) return;
	if (rnk[a] == rnk[b] && siz[a] < siz[b]) swap(a, b);
	else if (siz[a] < siz[b]) swap(a, b);
	siz[a] += siz[b];
	par[b] = a;	comp--;
	rnk[a]++;
}
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
	init(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		nadj[u].insert(v);
		nadj[v].insert(u);
	}
	int last = -1;
	comp = n;
	for (int i = 0; i < n; i++)
		if (n - nadj[i].size() <= n / 2) {
			for (int j = 0; j < n; j++)
				if (j != i && !nadj[i].count(j))
					adj[i].emplace_back(j);
		} else {
			if (last != -1) add(last, i);
			last = i;
		}
	for (int i = 0; i < n; i++)
		for (int j : adj[i])
			add(i, j);
	cout << comp - 1 << endl;
}