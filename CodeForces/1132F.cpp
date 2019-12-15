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
const int N = 500;
int n;
string s;
vector<vector<int>> dp;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> s;
	s.erase(unique(all(s)), s.end()); n = sz(s);
	dp.resize(n);
	rep(i, n) dp[i].resize(n);
	rep(i , n) rep(j, n) dp[i][j] = (i > j) ? 0 : N;
	rep(i, n) dp[i][i] = 1;
	repr(i, n) forn(j, i + 1, n) {
		dp[i][j] = 1 + dp[i][j - 1];
		forn(k, i, j) if (s[k] == s[j])
			dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j - 1]);
	}
	cout << dp[0][n - 1] << endl;
	return 0;
}