#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define fi first
#define se second
const int inf = 1e9;
int n, m, LOGN;

struct Edge {
	int u, v;
	int w, id;
	Edge() {}
	void read(int i) {
		cin >> u >> v >> w;
		u--; v--; id = i;
	}
	int other(int t) {return t ^ u ^ v;}
};
bool cmp(Edge a, Edge b) {return a.w < b.w;}

vector<Edge> edges;
vector<vector<int>> adj, mx, mn, P;
vector<int> par, ans, rnk, depth;
vector<bool> mst;

void init() {
	cin >> n >> m;
	int j = 0;
	for (; (1 << j) < n; j++);
	LOGN = j;
	edges.resize(m);
	mst.resize(m);
	ans.resize(m);
	adj.resize(n);
	par.assign(n, -1);
	rnk.assign(n, 0);
	P.assign(n, vector<int>(LOGN, -1));
	mx.assign(n, vector<int>(LOGN, -inf));
	mn.assign(n, vector<int>(LOGN, inf));
	depth.assign(n, 0);
}
int root(int a) {
	if (par[a] == -1) par[a] = a;
	int _a = a;
	while (a != par[a]) a = par[a];
	par[_a] = a;
	return a;
}
bool add(int i) {
	int a = root(edges[i].u), b = root(edges[i].v);
	if (a == b) return false;
	if (rnk[a] < rnk[b]) swap(a, b);
	par[b] = a; rnk[a]++;
	return true;
}
void kruskal() {
	vector<Edge> tmp = edges;
	sort(tmp.begin(), tmp.end(), cmp);
	for (int i = 0; i < m; i++)
		mst[tmp[i].id] = add(tmp[i].id);
}
void dfs(int v, int pr = -1) {
	P[v][0] = pr;
	for (int i : adj[v]) {
		int u = edges[i].other(v);
		if (u == pr) continue;
		mx[u][0] = edges[i].w;
		depth[u] = depth[v] + 1;
		dfs(u, v);
	}
}
void pre_process() {
	for (int j = 1; j < LOGN; j++)
		for (int i = 0; i < n; i++)
			if (P[i][j - 1] != -1)
				P[i][j] = P[P[i][j - 1]][j - 1];

	for (int j = 1; j < LOGN; j++)
		for (int i = 0; i < n; i++)
			if (P[i][j - 1] != -1)
				mx[i][j] = max(mx[i][j - 1], mx[P[i][j - 1]][j - 1]);
}
void post_process() {
	for (int j = LOGN - 1; j > 0; j--)
		for (int i = 0; i < n; i++) {
			mn[i][j - 1] = min(mn[i][j - 1], mn[i][j]);
			if (P[i][j - 1] == -1) continue;
			mn[P[i][j - 1]][j - 1] = min(mn[P[i][j - 1]][j - 1], mn[i][j]);
		}
}
int lca(int p, int q) {
	if (depth[p] < depth[q]) swap(p, q);
	for (int i = LOGN - 1; i >= 0; i--)
		if (depth[p] - depth[q] >= (1 << i))
			p = P[p][i];
	if (p == q)	return p;
	for (int i = LOGN - 1; i >= 0; i--)
		if (P[p][i] != -1 && P[p][i] != P[q][i])
			p = P[p][i], q = P[q][i];
	return P[p][0];
}
int getmx(int v, int pr) {
	int ret = -inf;
	for (int i = LOGN - 1; i >= 0; i--)
		if (depth[v] - depth[pr] >= (1 << i)) {
			ret = max(ret, mx[v][i]);
			v = P[v][i];
		}
	return ret;
}
void update(int v, int pr, int w) {
	for (int i = LOGN - 1; i >= 0; i--)
		if (depth[v] - depth[pr] >= (1 << i)) {
			mn[v][i] = min(mn[v][i], w);
			v = P[v][i];
		}
}
int getmn(int v, int pr) {
	int ret = inf;
	for (int i = LOGN - 1; i >= 0; i--)
		if (depth[v] - depth[pr] >= (1 << i)) {
			ret = min(ret, mn[v][i]);
			v = P[v][i];
		}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	init();
	for (int i = 0; i < m; i++)
		edges[i].read(i);
	kruskal();
	for (auto e : edges) {
		if (!mst[e.id]) continue;
		adj[e.v].emplace_back(e.id);
		adj[e.u].emplace_back(e.id);
	}
	int root = 0;
	depth[root] = 0;
	dfs(root);
	pre_process();
	for (auto e : edges) {
		if (mst[e.id]) continue;
		int pr = lca(e.u, e.v);
		ans[e.id] = max(getmx(e.u, pr), getmx(e.v, pr));
		update(e.u, pr, e.w);
		update(e.v, pr, e.w);
	}
	post_process();
	for (auto e : edges) {
		if (!mst[e.id]) continue;
		int pr = lca(e.u, e.v);
		ans[e.id] = min(getmn(e.u, pr), getmn(e.v, pr));
	}
	for (int i : ans) cout << i << endl;
}