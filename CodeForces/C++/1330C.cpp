#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> l(m);
	for (int i = 0; i < m; i++)
		cin >> l[i];
	ll sum = 0;
	bool flag = true;
	for (int i = 0; i < m; i++) {
		sum += l[i];
		if (i > n - l[i]) flag = false;
	}
	flag = flag && (sum >= n);
	if (!flag) {
		cout << -1 << endl;
		return 0;
	}
	int ans[m];
	ans[m - 1] = n - l[m - 1] + 1;
	for (int i = m - 2; i >= 0; i--) {
		ans[i] = max(i + 1, ans[i + 1] - l[i]);
	}
	for (int i = 0; i < m; i++)
		cout << ans[i] << " ";
	cout << endl;
}