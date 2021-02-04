#include<bits/stdc++.h>
using namespace std;

using ll = long long;
vector<int> arr;
ll solve(int s, int e) {
	if (s >= e) return 0;
	int mn = *min_element(arr.begin() + s, arr.begin() + e);
	int prv = s; ll ans = mn;
	for (int i = s; i < e; i++) {
		arr[i] -= mn;
		if (arr[i] != 0) continue;
		ans += solve(prv, i);
		prv = i + 1;
	}
	ans += solve(prv, e);
	return min(ans, (ll)e - s);
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << solve(0, n) << endl;
}