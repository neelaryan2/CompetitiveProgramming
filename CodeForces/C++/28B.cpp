#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> siz, par, p, d;
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
	if (siz[a] == siz[b] && a > b) swap(a, b);
	else if (siz[a] < siz[b]) swap(a, b);
	siz[a] += siz[b];
	par[b] = a;
}
void init(int n) {
	siz.assign(n, 1);
	par.assign(n, -1);
	p.assign(n, -1);
	d.assign(n, -1);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	init(n);
	for (int i = 0; i < n; i++)
		cin >> p[i], p[i]--;
	for (int i = 0; i < n; i++)
		cin >> d[i];
	for (int i = 0; i < n; i++) {
		if (i + d[i] < n) add(p[i], p[i + d[i]]);
		if (i - d[i] >= 0) add(p[i], p[i - d[i]]);
	}
	vector<set<int>> adj(n);
	for (int i = 0; i < n; i++)
		adj[root(i)].insert(p[i]);
	for (int i = 0; i < n; i++)
		adj[root(i)].erase(i);
	for (int i = 0; i < n; i++)
		if (!adj[i].empty())
			return puts("NO"), 0;
	puts("YES");
}