#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, a, b) for (int i = a; i < b; i++)
#define rfor(i, b, a) for (int i = b; i > a; i--)
#define rep(i, n) for (int i = 1; i <= n; i++)
#define repr(i, n) for (int i = n ; i > 0; i--)
#define forv(i, v) for (auto i = v.begin(); i != v.end(); i++)
#define all(v) v.begin(), v.end()
#define sz(v) int(v.size())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define pp pair<int, int>
#define vi vector<int>
#define endl "\n"
const int N = 703;
int n;
bool dp[N][N][2];
int a[N], edge[N][N];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n; rep(i, n) cin >> a[i];
	rep(i, n) rep(j, n) edge[i][j] = (__gcd(a[i], a[j]) > 1);
	forn(i, 0, N) forn(j, 0, N) dp[i][j][0] = dp[i][j][1] = false;
	rep(i, n) dp[i][i][0] = dp[i][i][1] = true;
	rep(len, n) rep(left, n - len + 1) {
		int right = left + len - 1;
		forn(root, left, right + 1) {
			dp[left][right][0] |= dp[left + 1][root][1] && dp[root][right][0] && edge[left][root];
			dp[left][right][1] |= dp[left][root][1] && dp[root][right - 1][0] && edge[right][root];
		}
	}
	if (dp[1][n][0] || dp[1][n][1])
		cout <<  "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}