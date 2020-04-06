#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define fi first
#define se second
const int inf = 1e9;
vector<int> a;
int dp[10][10][10];

int solve(int x, int y) {
	int ans = 0;
	for (int i = 0; i < a.size(); i++) {
		int curr = dp[x][y][a[i]];
		if (curr == inf) return -1;
		ans += curr - 1;
	}
	return ans;
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s; cin >> s;
	vector<int> tmp;
	int off = (s[0] == '0');
	if (!off) tmp.emplace_back(0);
	for (char c : s) tmp.emplace_back(c - '0');

	for (int i = 1; i < tmp.size(); i++)
		a.emplace_back((tmp[i] - tmp[i - 1] + 10) % 10);

	int ans[10][10];

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			for (int k = 0; k < 10; k++)
				dp[i][j][k] = inf;

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			for (int k = 0; k < 10; k++)
				for (int l = 0; l < 10; l++) {
					if (k == 0 && l == 0) continue;
					int curr = (i * k + j * l) % 10;
					int& t = dp[i][j][curr];
					t = min(t, k + l);
				}

	for (int i = 0; i < 10; i++) {
		for (int j = i; j < 10; j++) {
			ans[i][j] = ans[j][i] = -1;
			int curr = solve(i, j);
			if (curr < 0) continue;
			if (!off) curr++;
			ans[i][j] = ans[j][i] = curr;
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			cout << ans[i][j] << " ";
		cout << endl;
	}
}