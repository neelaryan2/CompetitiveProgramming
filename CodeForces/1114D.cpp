#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define mp make_pair
#define fi first
#define se second

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	int col[n], dp[n][n][2];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k : {0, 1})
				if (i == j) dp[i][i][k] = 0;
				else dp[i][j][k] = INT_MAX;
	for (int i = 0; i < n; i++)
		cin >> col[i];
	for (int len = 2; len <= n; len++) {
		for (int i = 0, j = len - 1; j < n; i++, j++) {
			dp[i][j][0] = min(dp[i][j][0], dp[i + 1][j][0] + (col[i + 1] != col[i]));
			dp[i][j][0] = min(dp[i][j][0], dp[i + 1][j][1] + (col[j] != col[i]));
			// dp[i][j][0] = min(dp[i][j][0], dp[i][j - 1][0] + (col[i] != col[i]));
			// dp[i][j][0] = min(dp[i][j][0], dp[i][j - 1][1] + (col[j - 1] != col[i]));

			// dp[i][j][1] = min(dp[i][j][1], dp[i + 1][j][0] + (col[i + 1] != col[j]));
			// dp[i][j][1] = min(dp[i][j][1], dp[i + 1][j][1] + (col[j] != col[j]));
			dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][0] + (col[i] != col[j]));
			dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][1] + (col[j - 1] != col[j]));
		}
	}
	cout << min(dp[0][n - 1][0], dp[0][n - 1][1]) << endl;
}