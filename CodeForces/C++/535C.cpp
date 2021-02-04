#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define mp make_pair
#define fi first
#define se second
#define vi vector<int>
ll n, A, B, l, t, m;
bool check(ll r) {
	ll res = (r * (r - 1)) / 2 - ((l - 1) * (l - 2)) / 2;
	res = res * B + (r - l + 1) * A;
	return (res <= m * t);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> A >> B >> n;
	while (n--) {
		cin >> l >> t >> m;
		ll up = (t - A) / B + 1;
		ll lo = l, hi = up + 1, mid;
		if (up < l) {
			cout << -1 << endl;
			continue;
		}
		while (lo < hi - 1) {
			mid = lo + (hi - lo) / 2;
			if (check(mid)) lo = mid;
			else hi = mid;
		}
		cout << (check(l) ? lo : -1) << endl;
	}
}