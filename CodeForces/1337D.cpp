#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define mp make_pair
#define fi first
#define se second
const ll inf = LLONG_MAX;
void update(ll& ans, ll a, ll b, ll c) {
	ll res = 0;
	res += (a - b) * (a - b);
	res += (c - b) * (c - b);
	res += (a - c) * (a - c);
	ans = min(ans, res);
}
void solve() {
	int n[3];
	set<ll> s[3];
	for (int i = 0; i < 3; i++)
		cin >> n[i];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n[i]; j++) {
			ll a; cin >> a;
			s[i].insert(a);
		}
	}
	ll ans = inf;
	for (int i = 0; i < 3; i++) {
		for (ll a : s[i]) {
			auto it1 = s[(i + 1) % 3].upper_bound(a);
			if (it1 != s[(i + 1) % 3].end()) {
				ll b = *it1;
				ll p = (a + b) / 2;
				auto it2 = s[(i + 2) % 3].upper_bound(p);
				if (it2 != s[(i + 2) % 3].end()) {
					ll c = *it2;
					update(ans, a, b, c);
				}
				if (it2 != s[(i + 2) % 3].begin()) {
					ll c = *(--it2);
					update(ans, a, b, c);
				}

			}
			if (it1 != s[(i + 1) % 3].begin()) {
				ll b = *(--it1);
				ll p = (a + b) / 2;
				auto it2 = s[(i + 2) % 3].upper_bound(p);
				if (it2 != s[(i + 2) % 3].end()) {
					ll c = *it2;
					update(ans, a, b, c);
				}
				if (it2 != s[(i + 2) % 3].begin()) {
					ll c = *(--it2);
					update(ans, a, b, c);
				}

			}
		}
	}
	cout << ans << endl;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while (t--) solve();
}