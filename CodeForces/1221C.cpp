#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void disp(vector<int> a) {
	for (int i : a)
		cout << i;
	cout << endl;
}
int solve() {
	int n, m, x;
	cin >> n >> m >> x;
	if (m < n) swap(m, n);
	int ans = min(n, x + m - n);
	n = 2 * (n - ans);
	ans += n / 3;
	return ans;
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int q; cin >> q;
	while (q--) cout << solve() << endl;
}