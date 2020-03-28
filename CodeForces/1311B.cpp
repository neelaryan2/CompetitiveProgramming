#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, m; cin >> n >> m;
	int p[m], a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> p[i];
	sort(p, p + m);
	int s = 0, e = 1;
	for (int i : p) {
		if (e == i) e++;
		else {
			sort(a + s, a + e);
			s = i - 1; e = i + 1;
		}
	}
	sort(a + s, a + e);
	puts(is_sorted(a, a + n) ? "YES" : "NO");
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int t; cin >> t;
	while (t--) solve();
}