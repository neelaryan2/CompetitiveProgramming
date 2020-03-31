#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
using pii = pair<int, int>;
using ll = long long;
const int inf = 4e5 + 5;

vector<int> cnt0(inf, 0), cnt1(inf, 0);
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, pos;
	cin >> n >> m; m--;
	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		int curr; cin >> curr; curr--;
		if (curr == m) pos = i;
		p[i] = curr;
	}
	vector<int> dp1(pos + 1, n + 1), dp2(1, n);
	for (int i = pos - 1; i >= 0; i--) {
		dp1[i] = dp1[i + 1] + ((p[i] <= m) ? 1 : -1);
	}
	for (int i = pos + 1; i < n; i++) {
		dp2.emplace_back(dp2.back() + ((p[i] <= m) ? 1 : -1));
	}
	ll ans = 0;
	for (int i = pos; i >= 0; i--)
		if (i % 2) cnt1[dp1[i]]++;
		else cnt0[dp1[i]]++;
	for (int i = pos; i < n; i++) {
		int curr = 2 * n - dp2[i - pos] + 1;
		if (i % 2) ans += cnt1[curr] + cnt0[curr - 1];
		else ans += cnt0[curr] + cnt1[curr - 1];
	}
	cout << ans << endl;
}