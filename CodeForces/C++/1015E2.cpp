#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define S second
#define F first
#define f(i,j,k,l) for(int i =j; i!=k; i = i + l)
typedef pair<int, int> pi;
typedef pair<pi, pi> ppi;
#define endl '\n'

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	vector<vector<ppi>> dp;
	int n, m;
	cin >> n >> m;
	dp.resize(n, vector<ppi>(m));
	f(i, 0, n, 1) {
		f(j, 0, m, 1) {
			char x;	cin >> x;
			int y = (x == '*');
			int z = y, k = y;
			if (i > 0) {
				z = y == 1 ? 1 + dp[i - 1][j].F.S : 0;
			}
			if (j > 0) {
				k = y == 1 ? 1 + dp[i][j - 1].S.S : 0;
			}
			dp[i][j] = {{y, z}, {y, k}};
		}
	}
	f(i, n - 1, -1, -1) {
		f(j, m - 1, -1, -1) {
			int y = dp[i][j].F.F;
			int z = y, k = y;
			if (i < n - 1) {
				z = y == 1 ? 1 + dp[i + 1][j].F.F : 0;
			}
			if (j < m - 1) {
				k = y == 1 ? 1 + dp[i][j + 1].S.F : 0;
			}
			dp[i][j].F.F = z;
			dp[i][j].S.F = k;
		}
	}
	f(i, 0, n, 1) {
		f(j, 0, m, 1) {
			dp[i][j].F.F = min(min(dp[i][j].F.F, dp[i][j].F.S), min(dp[i][j].S.F, dp[i][j].S.S));
			dp[i][j].F.F--;
		}
	}

	vector<vector<pi>> dp2(n, vector<pi>(m, {0, 0}));
	int num = 0;
	vector<pi> st;
	f(i, 0, n, 1) {
		f(j, 0, m, 1) {
			int sz = dp[i][j].F.F;
			if (sz > 0) {
				num++;
				st.push_back({i + 1, j + 1});
				dp2[i][j - sz].F++;
				if (j + sz + 1 < m) {
					dp2[i][j + sz + 1].F--;
				}
				dp2[i - sz][j].S++;
				if (i + sz + 1 < n) {
					dp2[i + sz + 1][j].S--;
				}
			}
		}
	}
	bool x = 1;
	f(i, 0, n, 1) {
		f(j, 0, m, 1) {
			if (i > 0) {
				dp2[i][j].S = dp2[i][j].S + dp2[i - 1][j].S;
			}
			if ( j > 0) {
				dp2[i][j].F = dp2[i][j].F + dp2[i][j - 1].F;
			}
			if (dp[i][j].F.F >= 0 && dp2[i][j].F <= 0 && dp2[i][j].S <= 0) {
				x = 0;
				break;
			}
		}
		if (!x) {
			break;
		}
	}

	if (!x) {
		cout << -1 << endl;
	} else {
		cout << num << endl;
		for (auto p : st) {
			cout << p.F << " " << p.S << " " << dp[p.F - 1][p.S - 1].F.F << endl;
		}
	}

}