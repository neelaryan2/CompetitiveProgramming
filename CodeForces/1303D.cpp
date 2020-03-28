#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxb = 65;

int solve() {
	ll n, m, ans = 0;
	cin >> n >> m;
	vector<bool> v(maxb, 0);
	vector<int> cnt(maxb, 0);

	for (int i = 0; n; i++, n >>= 1)
		v[i] = n & 1;

	for (int i = 0; i < m; i++) {
		int a; cin >> a;
		a = int(log2(a));
		cnt[a]++;
	}
	for (int i = 0; i < maxb - 1; i++) {
		if (cnt[i] == 0 && v[i]) {
			int j = i;
			while (j < maxb && cnt[j] == 0) j++;
			if (j == maxb) return -1;
			cnt[j]--;
			ans += j - i; i = j - 1;
			continue;
		}
		cnt[i] -= (int)v[i];
		cnt[i + 1] += cnt[i] >> 1;
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
	int t; cin >> t;
	while (t--) cout << solve() << endl;
}