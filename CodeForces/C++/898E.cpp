#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; cin >> n;
	vector<int> cnt(3), arr(n);
	for (int i = 0; i < n; i++) {
		ll a, tmp; cin >> a; tmp = a;
		a = (int)sqrt(a);
		arr[i] = min(tmp - a * a, a * a + 2 * a + 1 - tmp);
		a = a * a;
		if (a != tmp) tmp = 0;
		else if (a == 0) tmp = 2;
		else tmp = 1;
		cnt[tmp]++;
	}
	sort(arr.begin(), arr.end());
	ll ans = 0;
	if (cnt[0] == n / 2) {
		cout << 0 << endl;
		return 0;
	}
	if (cnt[0] < n / 2) {
		int need = n / 2 - cnt[0];
		ans += min(need, cnt[1]);
		need -= min(need, cnt[1]);
		ans += 2 * min(need, cnt[2]);
		cout << ans << endl;
		return 0;
	}
	for (int i = 0; i < n / 2; i++)
		ans += arr[i];
	cout << ans << endl;
}