#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> p(n), vis(n, false), ans(n);
	for (int i = 0; i < n; i++)
		cin >> p[i], p[i]--;
	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;
		int j = p[i], cnt = 1;
		while (j != i) j = p[j], cnt++;
		for (int k = 0; k < cnt; k++) {
			vis[j] = true;
			ans[j] = cnt;
			j = p[j];
		}
	}
	for (int i : ans) cout << i << " ";
	cout << endl;
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q; cin >> q;
	while (q--) solve();
}