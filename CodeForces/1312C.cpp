#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxb = 64;
string solve() {
	int n, k; cin >> n >> k;
	vector<bool> vis(maxb, false);
	vector<ll> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; a[i]; j++) {
			ll curr = a[i] % k; a[i] /= k;
			if (curr == 0) continue;
			if (curr != 1) return "NO";
			if (vis[j]) return "NO";
			vis[j] = true;
		}
	}
	return "YES";
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int t; cin >> t;
	while (t--) cout << solve() << endl;
}