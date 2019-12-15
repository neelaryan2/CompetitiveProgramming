#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, a, b) for (int i = a; i < b; i++)
#define rfor(i, b, a) for (int i = b; i > a; i--)
#define rep(i, n) for (int i = 0; i < n; i++)
#define forv(i, v) for (auto i = v.begin(); i != v.end(); i++)
#define all(v) v.begin(), v.end()
#define fi first
#define se second
const int N = int(1e9);
vector<vector<ll>> dp;
vector<int> a;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	a.resize(n); dp.resize(n);
	rep(i, n) cin >> a[i], dp[i].resize(m);
	rep(i, n) rep(j, m) dp[i][j] = 0;
	dp[0][0] = a[0] - k;
	rep(i, m) dp[0][i] = -1e18;
	forn(i, 1, n) {
		rep(j, m) dp[i][j] = a[i] + dp[i - 1][j];
		dp[i][i % m] = a[i] - k + max(0LL, dp[i - 1][i % m]);
	}
	ll ans = 0;
	rep(i, n) rep(j, m) ans = max(ans, dp[i][j]);
	cout << ans << endl;
	return 0;
}