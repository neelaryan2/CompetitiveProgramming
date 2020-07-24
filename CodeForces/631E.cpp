#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
// clang-format off
struct Line {
    mutable ll k, m, p;
    bool operator<(const Line& o) const { return k < o.k; }
    bool operator<(ll x) const { return p < x; }
};
struct ConvexHull : multiset<Line, less<>> {
    // (for doubles, use inf = 1/.0, div(a,b) = a/b)
    const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
    void add(ll k, ll m) {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    ll query(ll x) {
        assert(!empty());
        auto l = *lower_bound(x);
        return l.k * x + l.m;
    }
};
// clang-format on

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<ll> a(n + 1, 0), p(n + 1, 0);
    ll base = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        base += i * a[i];
        p[i] = p[i - 1] + a[i];
    }
    ConvexHull hull;
    ll ans = 0;

    hull.add(0, 0);
    for (int i = 1; i <= n; i++) {
        ll cur = hull.query(a[i]);
        ans = max(ans, cur + p[i] - i * a[i]);
        hull.add(i, -p[i]);
    }
    hull.clear();
    hull.add(0, 0);
    for (int i = n; i >= 1; i--) {
        ll cur = hull.query(a[i]);
        ans = max(ans, cur + p[i] - i * a[i]);
        hull.add(i, -p[i]);
    }
    ans += base;
    cout << ans << '\n';
}
