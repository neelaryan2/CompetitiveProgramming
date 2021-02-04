#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using pll = pair<ll, ll>;
#define fi first
#define se second
const ll inf = 1e18;

typedef
tree <
pll,
null_type,
less<pll>,
rb_tree_tag,
tree_order_statistics_node_update >
ordered_set;

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; cin >> n;
	vector<pll> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i].fi;
	for (int i = 0; i < n; i++)
		cin >> arr[i].se;
	sort(arr.begin(), arr.end());
	ll ans = 0;
	ordered_set s;
	for (pll p : arr) {
		int k = s.order_of_key(make_pair(p.se, inf));
		ans += 1LL * k * p.fi;
		s.insert(make_pair(p.se, p.fi));
	}
	s.clear();
	reverse(arr.begin(), arr.end());
	for (pll p : arr) {
		int k = s.order_of_key(make_pair(p.se, -inf));
		ans -= 1LL * (s.size() - k) * p.fi;
		s.insert(make_pair(p.se, p.fi));
	}
	cout << ans << endl;
}