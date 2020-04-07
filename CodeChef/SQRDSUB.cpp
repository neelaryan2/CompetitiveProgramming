#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n; cin >> n;
	ll dp[n + 1][3], ans = 0;
	dp[0][0] = dp[0][1] = dp[0][2] = 0;
	for (int i = 1; i <= n; i++) {
		int a, c; cin >> a; c = 0;
		while (a % 2 == 0) {
			a /= 2; c++;
			if (c == 2) break;
		}
		if ( c == 2) {
			dp[i][2] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + 1;
			dp[i][1] = 0;
			dp[i][0] = 0;
		} else if (c == 1) {
			dp[i][2] = dp[i - 1][1] + dp[i - 1][2];
			dp[i][1] = dp[i - 1][0] + 1;
			dp[i][0] = 0;
		} else {
			dp[i][2] = dp[i - 1][2];
			dp[i][1] = dp[i - 1][1];
			dp[i][0] = dp[i - 1][0] + 1;
		}
		ans += dp[i][0] + dp[i][2];
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