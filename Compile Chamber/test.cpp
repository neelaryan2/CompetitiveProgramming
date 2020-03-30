#include<bits/stdc++.h>
using namespace std;

long long n, a, b, m, k, l;
/*
long long parent[1000000],depth[1000000],vec[1000000];
vector<long long> adj[1000000];
long long p[1000000][20];
*/
vector<long long> parent, depth, vec;
vector<vector<long long>> adj, p;

long long power(long long x, long long y) {
	long long res = 1;
	while (y > 0) {
		if (y % 2 == 1) {
			res = res * x;
			y--;
		}
		y = y / 2;
		x = x * x;
	}
	return res;
}

long long log(long long n) {
	long long cnt = 0;
	while (n > 1) {
		n = n / 2;
		cnt++;
	}
	return cnt;
}

void init() {
	vector<long long> v(n);
	parent = v;
	depth = v;
	vec = v;
	vector<vector<long long>> z(n, vector<long long>());
	vector<vector<long long>> zz(n, vector<long long>(log(2 * n), -1));
	adj = z;
	p = zz;
}

void bfs(long long s) {
	parent[s] = -1;
	depth[s] = 0;
	queue<long long> q;
	q.push(s);
	while (!q.empty()) {
		for (long long i = 0; i < adj[q.front()].size(); i++) {
			if (adj[q.front()][i] != parent[q.front()]) {
				parent[adj[q.front()][i]] = q.front();
				depth[adj[q.front()][i]] = depth[q.front()] + 1;
				q.push(adj[q.front()][i]);
			}
		}
		q.pop();
	}
}

void P() {
	for (long long i = 1; i < n; i++) {
		p[i][0] = parent[i];
	}
	int l = p[0].size();
	for (long long j = 1; j < l; j++) {
		for (long long i = 1; i < n; i++) {
			if (p[i][j - 1] != -1) {
				p[i][j] = p[p[i][j - 1]][j - 1];
			}
		}
	}
}

long long kth(long long s, long long k) {
	if (k > depth[s]) {
		return -1;
	}
	if (k == 0) {
		return s;
	}
	long long d = 0, f = 2;
	while (f <= k) {
		d++;
		f = f * 2;
	}
	return kth(p[s][d], k - power(2, d));
}

long long lca(long long x, long long y) {
	if (x == y) {
		return x;
	}
	if (parent[x] == parent[y]) {
		return parent[x];
	}
	if (depth[x] == depth[y]) {
		long long d = 0, f = 2;
		while (f <= depth[x]) {
			d++;
			f = f * 2;
		}
		while (p[x][d] == p[y][d]) {
			d--;
		}
		return lca(p[x][d], p[y][d]);
	}
	if (depth[x] > depth[y]) {
		return lca(kth(x, depth[x] - depth[y]), y);
	}
	return lca(kth(y, depth[y] - depth[x]), x);
}

void add_edge(long long a, long long b) {
	adj[a].push_back(b);
	adj[b].push_back(a);
}

bool comp(const long long & a, const long long & b) {
	return depth[a] > depth[b];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	init();

	for (long long i = 0; i < n - 1; i++) {
		cin >> a >> b;
		add_edge(a - 1, b - 1);
	}

	bfs(0);
	P();

	for (long long i = 0; i < m; i++) {
		bool possible = true;
		cin >> k;
		long long v[k];
		for (long long j = 0; j < k; j++) {
			cin >> v[j];
			v[j]--;
		}
		sort(v, v + k, comp);
		l = v[0];
		for (long long j = 1; j < k; j++) {
			l = lca(l, v[j]);
			if (depth[v[j]] - depth[l] > 1) {
				//cout<<l<<" "<<v[j]<<endl;
				possible = false;
			}
		}
		if (possible) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
}