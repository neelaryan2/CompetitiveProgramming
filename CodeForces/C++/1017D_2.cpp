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
int n, m, q, power2n, tot = 101, k;
vector<int> w, costs, counts;
vector<vector<int>> ans;

int my_stoi(string st) {
	int num = 0;
	rep(i, sz(st)) if (st[i] == '1') num ^= 1 << i;
	return num;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> q;
	string s;
	power2n = 1 << n;
	w.resize(n); costs.resize(power2n);
	counts.resize(power2n); ans.resize(power2n);
	rep(i, n) cin >> w[i];
	rep(i, power2n) {
		costs[i] = 0;
		counts[i] = 0;
		rep(j, n) if ((~i >> j) & 1) costs[i] += w[j];
	}
	rep(i, m) cin >> s, counts[my_stoi(s)]++;
	rep(i, power2n) {
		ans[i].resize(tot);
		rep(j, tot) ans[i][j] = 0;
	}
	int cost;
	rep(i, power2n) rep(j, power2n) {
		if ((cost = costs[j ^ i]) < tot) ans[i][cost] += counts[j];
	}
	rep(i, power2n) forn(j, 1, tot) ans[i][j] += ans[i][j - 1];
	rep(i, q) cin >> s >> k, cout << ans[my_stoi(s)][k] << endl;
	return 0;
}