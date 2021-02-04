/* Author - Neel Aryan (@neelaryan2) */
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
const ll inf = LLONG_MAX;
ll d(pll a, pll b) {
    return abs(a.fi - b.fi) + abs(a.se - b.se);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll x0, y0, ax, ay, bx, by;
    cin >> x0 >> y0 >> ax >> ay >> bx >> by;
    ll xs, ys, t;
    cin >> xs >> ys >> t;
    vector<pll> vec;
    while (x0 <= xs + t && y0 <= ys + t) {
        vec.pb({x0, y0});
        if ((inf - bx) / ax < x0) break;
        if ((inf - by) / ay < y0) break;
        x0 = ax * x0 + bx;
        y0 = ay * y0 + by;
    }
    int n = vec.size();
    int ans = 0;
    pll s = {xs, ys};
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            ll cur = min(d(s, vec[i]), d(s, vec[j]));
            if (cur > t) continue;
            bool bad = false;
            for (int k = i; k < j; k++) {
                cur += d(vec[k], vec[k + 1]);
                if (cur > t) {
                    bad = true;
                    break;
                }
            }
            if (bad) continue;
            ans = max(ans, j - i + 1);
        }
    }
    cout << ans << '\n';
}
