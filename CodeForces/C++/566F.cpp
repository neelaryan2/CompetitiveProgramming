#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
vector<int> dp(maxn, -1);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		dp[a] = 1;
	}
	for (int i = 0; i < maxn; i++) {
		if (dp[i] == -1) continue;
		for (int j = 2 * i; j < maxn; j += i) {
			if (dp[j] == -1) continue;
			dp[j] = max(dp[j], dp[i] + 1);
		}
	}
	int ans = *max_element(dp.begin(), dp.end());
	cout << ans << endl;
}
