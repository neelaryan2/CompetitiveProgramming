#include<bits/stdc++.h>
using namespace std;
const long long mod = 998244353;

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; cin >> n;
	vector<long long> ans(n, 10);
	long long ans1 = 18, ans2 = 10, pw = 1;
	for (int i = 1; i < n; i++) {
		ans1 = (10 * ans1) % mod;
		ans2 = (81 * (i - 1) * pw) % mod;
		pw = (10 * pw) % mod;
		ans[i] = (ans1 + ans2) % mod;
	}
	for (int i = n; i > 0; i--) cout << ans[i - 1] << " ";
	cout << endl;
}