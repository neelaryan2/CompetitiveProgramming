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
struct pt {
    ll x, y;
    pt(ll x = 0, ll y = 0) : x(x), y(y) {}
    bool operator<(const pt& a) { return x < a.x || (x == a.x && y < a.y); }
    friend bool cw(pt a, pt b, pt c) { return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0; }
    friend bool ccw(pt a, pt b, pt c) { return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0; }
};
void solve(int test) {
    int n, sz = 0;
    cin >> n;
    vector<ll> a(n + 1, 0);
    vector<pt> hull(1);
    for (int i = 1, e; i <= n; i++) {
        cin >> e;
        a[i] = a[i - 1] + e;
        pt p(i, a[i]);
        int sz = hull.size() - 1;
        while (sz >= 1 && !ccw(hull[sz - 1], hull[sz], p))
            hull.pop_back(), sz--;
        hull.push_back(p);
    }
    for (int i = 1; i < hull.size(); i++) {
        ld sum = hull[i].y - hull[i - 1].y;
        int len = hull[i].x - hull[i - 1].x;
        sum = sum / len;
        while (len--) cout << fixed << setprecision(9) << sum << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve(i);
        // cout << "\n";
    }
}
