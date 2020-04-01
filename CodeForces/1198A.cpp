#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, I, k;
	cin >> n >> I;
	k = (8 * I) / n;
	if (k > 20) {cout << 0 << endl; return 0;}
	int d = min(1 << k, n);
	if (d == n) {cout << 0 << endl; return 0;}
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	map<int, int> cnt;
	for (int i : arr) cnt[i]++;
	int ind = 1, m = cnt.size();
	if (d >= m) {cout << 0 << endl; return 0;}
	vector<ll> pref(m + 1, 0);
	for (auto p : cnt) pref[ind++] = p.second;
	for (int i = 1; i <= m; i++)
		pref[i] += pref[i - 1];
	ll mn = 1e9;
	for (int i = 0; i + d <= m; i++) {
		ll cost = pref[m] - pref[i + d] + pref[i];
		mn = min(cost, mn);
	}
	cout << mn << endl;
}
