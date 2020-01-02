#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define eb emplace_back
#define ll long long
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second

ll ans = 0;
int n, k;
vector<bool> bad;
vector<int> par, siz;
vector<pair<int, pi>> edges;

int root(int v) {
	return (v == par[v]) ? v : par[v] = root(par[v]);
}
bool addEdge(int a, int b) {
	a = root(a); b = root(b);
	if (bad[a] && bad[b]) return true;
	if (bad[a] || bad[b])
		bad[a] = bad[b] = true;
	if (a == b) return false;
	if (siz[a] == siz[b] && a > b) swap(a, b);
	else if (siz[a] < siz[b]) swap(a, b);
	siz[a] += siz[b];
	par[b] = a;
	return false;
}
int main() {
	cin >> n >> k;
	bad.resize(n, false);
	par.eb(0); siz.eb(1);
	for (int i = 1; i < n; i++) {
		int c1, c2, t;
		cin >> c1 >> c2 >> t;
		edges.eb(mp(t, mp(c1, c2)));
		par.eb(i); siz.eb(1);
	}
	for (int i = 0; i < k; i++) {
		int c; cin >> c;
		bad[c] = true;
	}
	sort(edges.rbegin(), edges.rend());
	for (int i = 0; i < n - 1; i++)
		if (addEdge(edges[i].se.fi, edges[i].se.se))
			ans += edges[i].fi;
	cout << ans << endl;
}