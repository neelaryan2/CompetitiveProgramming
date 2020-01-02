#include<bits/stdc++.h>
using namespace std;

map<int, int> siz, par;
int ans = 0;
int root(int v) {
	if (siz.find(v) == siz.end())
		siz[v] = 1, par[v] = v;
	return (v == par[v]) ? v : par[v] = root(par[v]);
}
void addEdge(int a, int b) {
	a = root(a); b = root(b);
	if (a == b) return;
	if (a > b) swap(a, b);
	siz[a] += siz[b];
	par[b] = a;
	ans = max(ans, siz[a]);
}
int main() {
	int m, a, b; cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		addEdge(a, b);
		cout << ans << endl;
	}
}