#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	int a[n], dp[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	map<int, int> pos;
	int mx = -1, val = -1;
	for (int i = 0; i < n; i++) {
		pos[a[i]] = i;
		if (pos.find(a[i] - 1) == pos.end()) dp[i] = 1;
		else dp[i] = dp[pos[a[i] - 1]] + 1;
		if (dp[i] > mx) {mx = dp[i]; val = a[i];}
	}
	cout << mx << endl;
	int ans[mx], j = mx;
	for (int i = n - 1; i >= 0; i--) {
		if (j == 0) break;
		if (a[i] != val) continue;
		ans[--j] = i + 1;
		val--;
	}
	for (int i = 0; i < mx; i++)
		cout << ans[i] << " ";
	cout << endl;
}