#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	#ifdef LOCAL
	    freopen("in.txt", "r", stdin);
	    freopen("out.txt", "w", stdout);
	#endif
	int n, k;
	cin >> n >> k;
	vector<int> a(n), here(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	int last = 0;
	for (int i = 0; i < n; i++) {
		while (last < n && a[last] - a[i] <= 5) last++;
		here[i] = last - i;
	}
	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
	for (int i = 0; i < n; i++) for (int j = 0; j <= k; j++) {
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
			if (j == k) continue;
			dp[i + here[i]][j + 1] = max(dp[i][j] + here[i], dp[i + here[i]][j + 1]);
		}
	cout << dp[n][k] << endl;

}