#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using ld = long double;
using pii = pair<ld, int>;
using vi = vector<int>;
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

const int inf = 1e9 + 7;

struct pt {
    int x, y;
    ld operator-(const pt& oth) {
        ld dx = x - oth.x;
        ld dy = y - oth.y;
        return sqrtl(dx * dx + dy * dy);
    }
    void read() {
        cin >> x >> y;
    }
    friend ostream& operator<<(ostream& os, pt const& a) {
        return os << "(" << a.x << "," << a.y << ")";
    }
};
void solve(int test) {
    pt a, b, t;
    a.read();
    b.read();
    t.read();
    int n;
    cin >> n;
    vector<pt> pts(n);
    vector<pii> pa(n), pb(n);
    ld tot = 0;
    trace(a, b, t);
    for (int i = 0; i < n; i++) {
        pts[i].read();
        ld c = (pts[i] - t);
        tot += c;
        pa[i].fi = (pts[i] - a) - c;
        pb[i].fi = (pts[i] - b) - c;
        pa[i].se = pb[i].se = i;
    }
    trace(pts);
    tot *= 2;
    if (n == 1) {
        tot += min(pa[0].fi, pb[0].fi);
    } else {
        ld cur;
        sort(all(pa)), sort(all(pb));
        if (pa[0].se == pb[0].se) {
            ld a1 = pa[0].fi + pb[1].fi;
            ld a2 = pa[1].fi + pb[0].fi;
            cur = min(a1, a2);
        } else
            cur = pa[0].fi + pb[0].fi;
        tot += min({pa[0].fi, pb[0].fi, cur});
    }
    cout << fixed << setprecision(12) << tot;
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
        cout << '\n';
    }
}
