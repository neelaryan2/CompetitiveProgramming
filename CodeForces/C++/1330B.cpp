#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(int st, int en, vector<int>& arr) {
	vector<bool> vis(en - st, false);
	for (int i = st; i < en; i++) {
		int c = arr[i] - 1;
		if (c < 0 || c >= en - st) return false;
		vis[c] = true;
	}
	bool flag = true;
	for (bool b : vis) flag = flag && b;
	return flag;
}
void solve() {
	int n; cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int mx = *max_element(arr.begin(), arr.end());
	vector<int> ans;
	if (check(0, mx, arr) && check(mx, n, arr))
		ans.emplace_back(mx);
	if (2 * mx != n && check(0, n - mx, arr) && check(n - mx, n, arr))
		ans.emplace_back(n - mx);
	cout << ans.size() << endl;
	for (int i : ans) cout << i << " " << n - i << endl;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int t; cin >> t;
	while (t--) solve();
}