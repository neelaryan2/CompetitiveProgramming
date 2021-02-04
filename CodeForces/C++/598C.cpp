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
using ppi = pair<pii, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
const ld pi = acos(-1);
ld angle(pii a) {
    ld m = sqrtl(a.fi * a.fi + a.se * a.se);
    ld ang = acos((ld)a.fi / m);
    ang *= (180.0 / pi);
    if (a.se < 0) ang = 360 - ang;
    return ang;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<ppi> vec(n);
    for (int i = 1; i <= n; i++) {
        pii p;
        cin >> p.fi >> p.se;
        vec[i - 1] = mp(p, i);
        trace(i, p);
    }
    sort(all(vec), [](ppi a, ppi b) {
        return angle(a.fi) < angle(b.fi);
    });
    vec.pb(vec[0]);
    for (ppi p : vec)
        trace(p.se, angle(p.fi));
    ld ang = 190;
    int i1 = -1, i2 = -1;
    for (int i = 1; i <= n; i++) {
        ld cur = angle(vec[i].fi) - angle(vec[i - 1].fi);
        if (cur < 0) cur += 360;
        cur = min(cur, 360 - cur);
        trace(cur);
        if (cur >= ang) continue;
        i1 = vec[i - 1].se, i2 = vec[i].se, ang = cur;
    }
    cout << i1 << " " << i2 << '\n';
}
