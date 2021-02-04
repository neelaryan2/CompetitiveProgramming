#include<bits/stdc++.h>
using namespace std;
vector<int> maxdp(1e5 + 5, 0);
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	vector<int> a(n);
	vector<vector<int>> div(n);
	for (int j = 0; j < n; j++) {
		cin >> a[j];
		int tmp = a[j];
		for (int i = 2; i * i <= tmp; i++) {
			if (tmp % i) continue;
			div[j].emplace_back(i);
			while (tmp % i == 0) tmp /= i;
		}
		if (tmp != 1) div[j].emplace_back(tmp);
	}
	vector<int> dp(n, 1);
	int mx = -1;
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		for (int j : div[i])
			dp[i] = max(dp[i], maxdp[j] + 1);
		for (int j : div[i])
			maxdp[j] = max(dp[i], maxdp[j]);
		mx = max(mx, dp[i]);
	}
	cout << mx << endl;
}