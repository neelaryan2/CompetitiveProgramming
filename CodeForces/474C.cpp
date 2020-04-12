#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define mp make_pair
#define fi first
#define se second
const int k = 4;
ll distSq(pii p, pii q) {
	return 1LL * (p.fi - q.fi) * (p.fi - q.fi) + 1LL * (p.se - q.se) * (p.se - q.se);
}
bool isSquare(pii p1, pii p2, pii p3, pii p4) {
	ll d12 = distSq(p1, p2);
	ll d13 = distSq(p1, p3);
	ll d14 = distSq(p1, p4);
	ll d23 = distSq(p2, p3);
	ll d24 = distSq(p2, p4);
	ll d34 = distSq(p3, p4);
	if (!(d12 && d13 && d14 && d23 && d24 && d34))
		return false;
	if (d12 == d13 && 2 * d12 == d14 && 2 * d24 == d23)
		return true;
	if (d13 == d14 && 2 * d13 == d12 && 2 * d23 == d34)
		return true;
	if (d12 == d14 && 2 * d12 == d13 && 2 * d23 == d24)
		return true;
	return false;
}
void solve() {
	int x, y, a, b, pw = 1, ans = 100;
	vector<vector<pii>> points(k);
	for (int i = 0; i < k; i++) {
		cin >> x >> y >> a >> b;
		points[i].resize(k);
		x -= a; y -= b; pw *= k;
		points[i][0] = mp(x, y);
		for (int j = 1; j < k; j++) {
			pii p = points[i][j - 1];
			points[i][j] = mp(-p.se, p.fi);
		}
		for (pii& p : points[i])
			p.fi += a, p.se += b;
	}
	for (int num = 0; num < pw; num++) {
		vector<int> dec(k, 0);
		int cpy = num, cost = 0, ind = k - 1;
		while (cpy) {
			dec[ind--] = cpy % k;
			cost += cpy % k; cpy /= k;
		}
		bool b = isSquare(points[0][dec[0]], points[1][dec[1]], points[2][dec[2]], points[3][dec[3]]);
		if (b && ans > cost) ans = cost;
	}
	cout << ((ans == 100) ? -1 : ans) << endl;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	while (n--) solve();
}