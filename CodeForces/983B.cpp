#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, a, b) for (int i = a; i < b; i++)
#define rfor(i, b, a) for (int i = b; i > a; i--)
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n - 1; i >=0; i--)
#define forv(i, v) for (auto i = v.begin(); i != v.end(); i++)
#define all(v) v.begin(), v.end()
#define sz(v) int(v.size())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
const int N = int(1e9);
int n, q, l, r;
vector<vector<int>> dp;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(15);
	cin >> n; dp.resize(n);
	rep(i, n) dp[i].resize(n - i);
	rep(i, n) cin >> dp[0][i];
	forn(i, 1, n) rep(j, n - i) dp[i][j] = dp[i - 1][j] ^ dp[i - 1][j + 1];
	forn(i, 1, n) rep(j, n - i) dp[i][j] = max({dp[i][j], dp[i - 1][j], dp[i - 1][j + 1]});
	cin >> q;
	rep(i, q) cin >> l >> r, cout << dp[r - l][l - 1] << endl;
	return 0;
}