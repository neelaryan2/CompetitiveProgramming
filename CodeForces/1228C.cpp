#include<bits/stdc++.h>
using namespace std;


#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c> {i, j}; }
sim > auto dud(c* x) -> decltype(cout << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
	~debug() { cout << endl; }
	eni( != ) cout << boolalpha << i; ris;
}
eni( == ) ris << range(begin(i), end(i));
}
sim, class b dor(pair < b, c > d) {
	ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
	*this << "[";
	for (auto it = d.b; it != d.e; ++it)
		*this << ", " + 2 * (it == d.b) << *it;
	ris << "]";
}
#else
	sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

typedef long long ll;
const int mod = 1e9 + 7;
ll expo(ll x, ll k) {
	ll ans = 1;
	while (k) {
		if (k & 1) ans = (ans * x) % mod;
		x = (x * x) % mod; k >>= 1;
	}
	return ans;
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ll n, x, ans = 1;
	cin >> x >> n;
	vector<int> p;
	for (int i = 2; i * i <= x; i++) {
		if (x % i) continue;
		p.emplace_back(i);
		while (x % i == 0) debug() << imie(x), x /= i;
	}
	if (x != 1) p.emplace_back(x);
	debug() << imie(p);
	for (int f : p) {
		ll curr = f, ex = 0;
		while (curr <= n) {
			ex += n / curr;
			if (curr > 1e18 / f) break;
			curr *= f;
		}
		ans = (ans * expo(f, ex)) % mod;
	}
	cout << ans << endl;
}