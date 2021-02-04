#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int ans = -1, sz = m - min(m - 1, k);
	for (int i = 0; i + sz - 1 < m; i++) {
		int mn = 1e9;
		for (int j = i; j < i + sz; j++)
			mn = min(mn, max(a[j], a[j + n - m]));
		ans = max(mn, ans);
	}
	cout << ans << endl;
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while (t--) solve();
}