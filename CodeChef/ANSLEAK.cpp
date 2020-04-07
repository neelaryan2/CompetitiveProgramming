#include<bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;
const ll mod = 1e9 + 7;
int gen(vector<ll>& cnt) {
	vector<ll> tmp(10);
	for (int i = 0; i < 10; i++)
		tmp[i] = (ll)pow(cnt[i], 5);
	discrete_distribution<int> dist(all(tmp));
	int r = dist(rng);
	return r;
}
void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	int C[n][k];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++)
			cin >> C[i][j];
	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		vector<ll> cnt(10, 0);
		for (int j = 0; j < k; j++)
			cnt[C[i][j]]++;
		ans[i] = gen(cnt);
	}
	for (int i : ans) cout << i << " "; cout << endl;
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while (t--) solve();
}