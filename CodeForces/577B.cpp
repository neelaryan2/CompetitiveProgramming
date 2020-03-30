#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define fi first
#define se second
#define vi vector<int>
const int inf = 1e9;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	if (n > m) {cout << "YES" << endl; return 0;}
	vector<vector<bool>> dp(n, vector<bool>(m, 0));
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i], a[i] %= m;
	for (int i = 0; i < n; i++)
		dp[i][a[i]] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!dp[i - 1][j]) continue;
			dp[i][(j + a[i]) % m] = 1;
			dp[i][j] = 1;
		}
	}
	cout << (dp[n - 1][0] ? "YES" : "NO") << endl;
}