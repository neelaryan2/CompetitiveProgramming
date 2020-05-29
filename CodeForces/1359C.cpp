/* Author - Neel Aryan (@neelaryan2) */
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

void solve() {
    int h, c, t;
    cin >> h >> c >> t;
    ld mn = ((ld)h + c) / 2;
    if ((ld)t <= mn) {
        cout << 2 << '\n';
        return;
    }
    ll ans = 2;
    auto cost = [&](ld k) {
        ld ret = (k + 1) * h + k * c;
        ret /= 2 * k + 1;
        return ret;
    };
    trace(cost(3));
    ll lo = 0, hi = 1e18, mid;
    while (lo < hi - 1) {
        mid = lo + (hi - lo) / 2;
        ld cur = cost(mid);
        if (cur >= t)
            lo = mid;
        else
            hi = mid;
    }
    ld curl = cost(lo);
    ld curh = cost(hi);
    ans = 2 * lo + 1;
    if (curh - t > t - curl) {
        ans = 2 * hi + 1;
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
