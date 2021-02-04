#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

const int inf = 1e9 + 7;
const int N = 2e5 + 5;

vector<int> divd[N], dist, par;
vector<vi> adj, tmp;
set<int> done;
int least[N];

pii bfs(int s) {
	queue<int> q;
	dist[s] = 1;
	par[s] = s;
	q.push(s);
	pii ret;
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		ret = mp(v, dist[v]);
		done.insert(v);
		for (int u : tmp[v]) {
			if (par[v] == u) 
				continue;
			par[u] = v;
			dist[u] = dist[v] + 1;
			q.push(u);
		}
	}
	return ret;
}

void sieve() {
	least[0] = 0; least[1] = 1;
	for (int i = 2; i < N; i++)
		least[i] = (i % 2) ? i : 2;
	for (int i = 3; i * i <= N; i += 2) {
		if (least[i] != i) continue;
		for (int j = i * i; j < N; j += i)
			if (least[j] == j)
				least[j] = i;
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	sieve();
    int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		int e; cin >> e;
		a[i] = e;
		while (e != 1) {
			int p = least[e];
			while (e % p == 0) 
				e /= p;
			divd[p].eb(i);
		}
	}
	adj.resize(n);
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].eb(v);
		adj[v].eb(u);
	}
	int ans = 0;
	tmp.resize(n);
	par.resize(n);
	dist.resize(n);
	for (int p = 2; p < N; p++) {
		for (int v : divd[p]) {
			tmp[v].clear();
			for (int u : adj[v])
				if (a[u] % p == 0)
					tmp[v].eb(u);
		}
		done.clear();
		for (int v : divd[p]) {
			if (done.find(v) != done.end()) continue;
			pii p1 = bfs(v);
			pii p2 = bfs(p1.fi);
			ans = max(ans, p2.se);
		}
	}
	cout << ans << '\n';
}
