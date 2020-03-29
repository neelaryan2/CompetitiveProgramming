#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using piii = pair<pii, int>;
using vs = vector<string>;
#define fi first
#define se second
const ll mod = 998244353;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, h, l, r;
	cin >> n >> h >> l >> r;
	int a[n + 1], dp[n + 1][n + 1];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i > 0) a[i] = (a[i] + a[i - 1]) % h;
	}
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			dp[i][j] = -1e9;
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			int k = (a[i - 1] - j) % h; if (k < 0) k += h;
			dp[i][j] = max(dp[i][j], dp[i - 1][j] + (l <= k && k <= r));
			k = (k - 1) % h;  if (k < 0) k += h;
			if (j != n) dp[i][j + 1] = max(dp[i][j + 1], dp[i - 1][j] + (l <= k && k <= r));
		}
	}
	int mx = -1;
	for (int i = 0; i <= n; i++)
		mx = max(mx, dp[n][i]);
	cout << mx << endl;
}