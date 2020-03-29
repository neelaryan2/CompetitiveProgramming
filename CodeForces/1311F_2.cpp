#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
#define fi first
#define se second
const ll inf = 1e18;

bool cmp(const pll& p1, const pll& p2) {
	if (p1.se != p2.se) return p1.se < p2.se;
	else return p1.fi < p2.fi;
}
vector<pll> arr;
ll merge(int s, int e) {
	if (s == e) return 0;
	int mid = (s + e) / 2;
	ll ans = merge(s, mid) + merge(mid + 1, e);
	sort(arr.begin() + s, arr.begin() + mid + 1, cmp);
	sort(arr.begin() + mid + 1, arr.begin() + e + 1, cmp);
	ll j = s, sum = 0, cnt = 0;
	for (int i = mid + 1; i <= e; i++) {
		while (j <= mid && arr[j].se <= arr[i].se)
			sum += arr[j++].fi, cnt++;
		ans += cnt * arr[i].fi - sum;
	}
	return ans;
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i].fi;
	for (int i = 0; i < n; i++)
		cin >> arr[i].se;
	sort(arr.begin(), arr.end());
	cout << merge(0, n - 1) << endl;
}