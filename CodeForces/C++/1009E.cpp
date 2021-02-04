#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
using pii = pair<int, int>;
using ll = long long;
const int inf = 4e5 + 5;
const ll kMod = 998244353;

vector<ll> a;
ll solve() {
	int n = a.size();
	ll ans = a[n - 1];
	if (n == 1) return ans;
	ll pw = 1, res;
	res = (2 * a[n - 2]) % kMod;
	ans = (ans + res) % kMod;
	if (n == 2) return ans;
	for (ll i = 2; i < n; i++) {
		res = ((i + 3) * pw) % kMod;
		res = (res * a[n - i - 1]) % kMod;
		ans = (ans + res) % kMod;
		pw = (pw * 2) % kMod;
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
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		ll e; cin >> e;
		a.emplace_back(e);
		if (i == 0) continue;
		a[i] = (a[i] + a[i - 1]) % kMod;
	}
	cout << solve() << endl;
}