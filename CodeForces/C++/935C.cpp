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

void solve(int test) {
    ld r, x1, y1, x2, y2;
    cin >> r >> x1 >> y1 >> x2 >> y2;
    ld dist = sqrtl((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    ld ans = (dist + r) / 2;
    ld xx = x2, yy = y2;
    if (dist > r)
        xx = x1, yy = y1, ans = r;
    else if (dist == 0)
        xx += ans;
    else {
        xx += (x1 - x2) * ans / dist;
        yy += (y1 - y2) * ans / dist;
    }
    cout << fixed << setprecision(16) << xx << ' ' << yy << ' ' << ans;
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
