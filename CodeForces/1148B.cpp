#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define fi first
#define se second
const ll inf = 1e18;

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, ta, tb, k;
	cin >> n >> m >> ta >> tb >> k;
	vector<ll> a(n), b(m);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];
	ll ans = -1;
	for (int i = 0; i <= k; i++) {
		if (i >= n) {ans = inf; break;}
		int ind = lower_bound(b.begin(), b.end(), a[i] + ta) - b.begin();
		ind += k - i;
		if (ind >= m) {ans = inf; continue;}
		ans = max(ans, b[ind] + tb);
	}
	cout << ((ans == inf) ? -1 : ans) << endl;
}