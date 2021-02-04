#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define fi first
#define se second

ll n, x, y;
string solve() {
	ll a; cin >> a;
	a = a % (x + y);
	if (a == 0 || a == x + y - 1)
		return "Both";
	ll lo = 0, hi = a * (x + y + 1), mid;
	while (lo < hi - 1) {
		mid = lo + (hi - lo) / 2;
		ll vanya = mid / x, vova = mid / y;
		if (vanya + vova <= a) lo = mid;
		else hi = mid;
	}
	if (lo % x < lo % y) return "Vanya";
	else return "Vova";
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	cin >> n >> x >> y;
	int g = __gcd(x, y);
	x /= g; y /= g;
	swap(x, y);
	while (n--) cout << solve() << endl;
}