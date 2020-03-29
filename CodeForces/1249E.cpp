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
	int n, c;
	cin >> n >> c;
	vector<int> a(n, 0), b(n, 0);
	vector<vector<int>>  dp(n, vector<int>(2, 0));
	for (int i = 1; i < n; i++)
		cin >> a[i];
	for (int i = 1; i < n; i++)
		cin >> b[i];
	cout << 0; dp[0][1] = c;
	for (int i = 1; i < n; i++) {
		dp[i][1] = b[i] + min(dp[i - 1][0] + c, dp[i - 1][1]);
		dp[i][0] = a[i] + min(dp[i - 1][0], dp[i - 1][1]);
		cout << " " << min(dp[i][0], dp[i][1]);
	}
	cout << endl;
}