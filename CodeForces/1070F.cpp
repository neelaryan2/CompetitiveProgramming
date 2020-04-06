#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int sz = 4;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; cin >> n;
	vector<ll> cnt[sz];
	for (int i = 0; i < n; i++) {
		char c1, c2; int k;
		cin >> c1 >> c2 >> k;
		int c = 2 * (c1 - '0') + c2 - '0';
		cnt[c].emplace_back(k);
	}
	for (int i = 0; i < sz; i++) {
		sort(cnt[i].rbegin(), cnt[i].rend());
		if (cnt[i].size() <= 1) continue;
		for (int j = 1; j < cnt[i].size(); j++)
			cnt[i][j] += cnt[i][j - 1];
	}
	if (cnt[1].size() > cnt[2].size()) swap(cnt[1], cnt[2]);
	int a = cnt[0].size(), b = cnt[1].size();
	int c = cnt[2].size(), d = cnt[3].size();

	ll tot = b ? cnt[2][b - 1] : 0;
	ll ans = tot, tmp = 0;
	ans += b ? cnt[1][b - 1] : 0;
	ans += d ? cnt[3][d - 1] : 0;
	for (int i = 0; i <= min(d, a); i++) {
		ll curr1 = i ? cnt[0][i - 1] : 0;
		int j = min(d - i, c - b);
		ll curr2 = j || b ? cnt[2][j + b - 1] : 0;
		tmp = max(tmp, curr1 + curr2 - tot);
	}
	cout << ans + tmp << endl;
}
