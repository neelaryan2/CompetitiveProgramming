#include<bits/stdc++.h>
using namespace std;

vector<int> siz, par;
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
inline void solve() {
	int n, m, cr, cl;
	cin >> n >> m >> cl >> cr;
	siz.assign(n, 1);
	par.assign(n, -1);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		add(x, y);
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		if (par[i] == -1) ans += cl;
		if (par[i] != i) continue;
		int s = siz[i]; ans += cl;
		ans += 1LL * (s - 1) * min(cl, cr);
	}
	cout << ans << endl;
}
int main() {
	int q;
	cin >> q;
	while (q--)
		solve();
}