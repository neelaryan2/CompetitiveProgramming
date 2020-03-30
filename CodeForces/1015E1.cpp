#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using piii = pair<pii, int>;
using vs = vector<string>;
#define fi first
#define se second
const ll inf = 1e18;

vector<vector<int>> ans, fig, check;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	fig.assign(n, vector<int>(m, 0));
	check.assign(n, vector<int>(m, '.'));
	ans.assign(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			char c; cin >> c;
			fig[i][j] = c;
		}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int k, ray = 200;
			for (k = i; k < n; k++)
				if (fig[k][j] == '.')
					break;
			ray = min(ray, k - i);
			for (k = i; k >= 0; k--)
				if (fig[k][j] == '.')
					break;
			ray = min(ray, i - k);
			for (k = j; k < m; k++)
				if (fig[i][k] == '.')
					break;
			ray = min(ray, k - j);
			for (k = j; k >= 0; k--)
				if (fig[i][k] == '.')
					break;
			ray = min(ray, j - k);
			if (ray <= 1) continue;
			ans[i][j] = ray;
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ans[i][j] < 2) continue;
			int k, ray = ans[i][j]; cnt++;
			for (k = i; k < i + ray; k++)
				check[k][j] = '*';
			for (k = i; k > i - ray; k--)
				check[k][j] = '*';
			for (k = j; k < j + ray; k++)
				check[i][k] = '*';
			for (k = j; k > j - ray; k--)
				check[i][k] = '*';
		}
	}
	bool same = true;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (check[i][j] != fig[i][j]) {
				same = false; break;
			}
	if (!same) {
		cout << -1 << endl;
		return 0;
	}
	cout << cnt << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ans[i][j] < 2) continue;
			cout << i + 1 << " " << j + 1 << " ";
			cout << ans[i][j] - 1 << endl;
		}
	}
}