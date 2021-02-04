#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, a, b) for (int i = a; i < b; i++)
#define rfor(i, b, a) for (int i = b; i > a; i--)
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n-1 ; i >=0; i--)
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
vector<int> a, minI, maxI, dp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q, n;
	cin >> q;
	while (q--) {
		cin >> n;
		a.resize(n); minI.resize(n);
		maxI.resize(n);
		rep(i, n) maxI[i] = -1, minI[i] = -1;
		rep(i, n) cin >> a[i], maxI[a[i] - 1] = i + 1;
		repr(i, n) minI[a[i] - 1] = i + 1;
		sort(all(a));
		a.erase(unique(all(a)), a.end());
		int maxi = 1; n = sz(a);
		dp.resize(n); dp[n - 1] = 1;
		repr(i, n - 1) {
			if (maxI[a[i] - 1] < minI[a[i + 1] - 1]) {
				dp[i] = dp[i + 1] + 1;
				maxi = max(maxi, dp[i]);
			} else dp[i] = 1;
		}
		cout << n - maxi << endl;
	}
	return 0;
}