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
int n, len, tot = 101, lo, hi;
vector<int> w;
vector<vector<vector<int>>> dp;

int my_stoi(string st) {
	int num = 0;
	rep(i, sz(st)) if (st[i] == '1') num ^= 1 << i;
	return num;
}
void update(string st) {
	int x = my_stoi(st.substr(0, n / 2));
	int y = my_stoi(st.substr(n / 2, len));
	rep(i, hi) {
		int cost = 0;
		rep(j, len)	if ((i & (1 << j)) == (y & (1 << j))) cost += w[n / 2 + j];
		if (cost < tot) dp[x][i][cost]++;
	}
}
int get(string st, int k) {
	int x = my_stoi(st.substr(0, n / 2));
	int y = my_stoi(st.substr(n / 2, len));
	int ans = 0;
	rep(i, lo) {
		int cost = 0;
		rep(j, n / 2) if ((i & (1 << j)) == (x & (1 << j))) cost += w[j];
		if (cost <= k) ans += dp[i][y][k - cost];
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s; int k, m, q;
	cin >> n >> m >> q;
	len = n - n / 2; lo = 1 << (n / 2); hi = 1 << len;
	w.resize(n);
	rep(i, n) cin >> w[i];
	dp.resize(lo);
	rep(i, lo) {
		dp[i].resize(hi);
		rep(j, hi) dp[i][j].resize(tot);
	}
	rep(i, lo) rep(j, hi) rep(t, tot) dp[i][j][t] = 0;
	rep(i, m) cin >> s, update(s);
	rep(i, lo) rep(j, hi) forn(t, 1, tot) dp[i][j][t] += dp[i][j][t - 1];
	rep(i, q) cin >> s >> k, cout << get(s, k) << endl;
	return 0;
}