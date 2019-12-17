#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, a, b) for (int i = a; i < b; i++)
#define rfor(i, b, a) for (int i = b; i > a; i--)
#define rep(i, n) for (int i = 1; i <= n; i++)
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
#define pp pair<int, int>
#define vi vector<int>
#define endl "\n"
const int N = 500005;
int n, c, ans = 0;
vi f(N, 0), a, cnt;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> c;
	a.resize(n + 1); cnt.resize(n + 1, 0);
	rep(i, n) cin >> a[i], cnt[i] = cnt[i - 1] + (a[i] == c);
	rep(i, n) {
		f[a[i]] = 1 + max(f[a[i]], cnt[i - 1]);
		ans = max(ans, f[a[i]] + cnt[n] - cnt[i]);
	}
	cout << ans << endl;
	return 0;
}