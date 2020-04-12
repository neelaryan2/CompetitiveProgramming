#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
#define mp make_pair
#define fi first
#define se second
#define vi vector<int>
const ll inf = LLONG_MAX;
template<typename T>
T extended_euclid(T a, T b, T &x, T &y) {
	T xx = 0, yy = 1; y = 0; x = 1;
	while (b) {
		T q = a / b, t = b; b = a % b; a = t;
		t = xx; xx = x - q * xx; x = t; t = yy; yy = y - q * yy; y = t;
	}
	return a;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n, p, w, d, x, y;
	cin >> n >> p >> w >> d;
	ll g = extended_euclid(w, d, x, y);
	if (p % g) {cout << -1 << endl; return 0;}
	w /= g; d /= g; p /= g;
	x = (x % d + d) % d; y = (y % w + w) % w;
	x = x * p - (ll)(x * (ld)p / d) * d; y = y * p - (ll)(y * (ld)p / w) * w;
	ll curr = x * w + y * d;
	if (curr > p) {cout << -1 << endl; return 0;}
	x += (p - curr) / w;
	if (x + y > n) {cout << -1 << endl; return 0;}
	cout << x << " " << y << " " << n - x - y << endl;
}