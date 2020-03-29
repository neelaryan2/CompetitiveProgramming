#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxb = 64;
string solve() {
	int n, k; cin >> n >> k;
	vector<bool> vis(maxb, false);
	for (int i = 0; i < n; i++) {
		ll a; cin >> a;
		for (int j = 0; a; j++) {
			ll curr = a % k; a /= k;
			if (curr == 0) continue;
			if (curr != 1) return "NO";
			if (vis[j]) return "NO";
			vis[j] = true;
		}
	}
	return "YES";
}
int main() {
	int t; cin >> t;
	while (t--) cout << solve() << endl;
}