#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	if (m > 2 * (n + 1) || m < n - 1) {
		cout << "-1\n";
		return 0;
	}
	vector<int> ans;
	if (m >= n) ans.emplace_back(1);
	ans.emplace_back(0);
	for (int i = 1; i < n; i++) {
		ans.emplace_back(1);
		ans.emplace_back(0);
	}
	if (m <= n) goto yes;
	ans.emplace_back(1);
	m -= n + 1;
	for (int i = 0; i < m; i++)
		ans[2 * i] = 11;
yes:
	for (int c : ans) cout << c;
	cout << endl; return 0;
}