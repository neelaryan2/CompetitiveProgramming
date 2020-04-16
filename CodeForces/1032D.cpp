#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
using ll = long long;
using ld = long double;
using pld = pair<ld, ld>;
ld dist(pld p1, pld p2) {
	return sqrtl((p1.fi - p2.fi) * (p1.fi - p2.fi) + (p1.se - p2.se) * (p1.se - p2.se));
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll a, b, c;
	cin >> a >> b >> c;
	pld p1, p2;
	cin >> p1.fi >> p1.se >> p2.fi >> p2.se;
	ld ans = abs(p1.fi - p2.fi) + abs(p1.se - p2.se);
	if (a == 0 || b == 0) {
		cout << fixed << setprecision(10) << ans << endl;
		return 0;
	}
	pld p11, p12;
	p11.fi = p1.fi; p12.se = p1.se;
	p11.se = (-c - a * p1.fi) / b;
	p12.fi = (-c - b * p1.se) / a;

	pld p21, p22;
	p21.fi = p2.fi; p22.se = p2.se;
	p21.se = (-c - a * p2.fi) / b;
	p22.fi = (-c - b * p2.se) / a;

	if (p11 > p12) swap(p11, p12);
	if (p21 > p22) swap(p21, p22);
	vector<pld> vec;
	vec.emplace_back(p11);
	vec.emplace_back(p12);
	vec.emplace_back(p21);
	vec.emplace_back(p22);
	sort(vec.begin(), vec.end());
	if (vec[0] == p11 && vec[2] == p21) {
		ans = dist(p1, vec[1]) + dist(vec[1], vec[2]) + dist(p2, vec[2]);

	} else if (vec[2] == p11 && vec[0] == p21) {
		ans = dist(p2, vec[1]) + dist(vec[1], vec[2]) + dist(p1, vec[2]);
	}
	cout << fixed << setprecision(10) << ans << endl;
	return 0;
}