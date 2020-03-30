#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int mod = 998244353;
const int inv2 = 499122177;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; cin >> n;
	vector<int> a(n);
	map<int, int> last;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		last[a[i]] = i;
	}
	int mx = 0, prev = 0;
	ll ans = 1;
	while (1) {
		for (int i = prev; i <= mx; i++)
			if (i <= mx)
				mx = max(mx, last[a[i]]);
		ans = (2LL * ans) % mod;
		if (mx == n - 1) break;
		prev = mx; mx = last[a[mx + 1]];
	}
	ans = (ans * inv2) % mod;
	cout << ans << endl;
}