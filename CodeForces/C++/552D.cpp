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
const int T = 100;
set<int> yes[2 * T + 1];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> xp(n), yp(n);
    for (int i = 0; i < n; i++) {
        cin >> xp[i] >> yp[i];
        yes[yp[i] + T].insert(xp[i]);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int x1 = xp[i], y1 = yp[i];
            int x2 = xp[j], y2 = yp[j];
            if (y1 == y2) {
                int yy = y1;
                for (int x = -T; x <= T; x++) {
                    if (x == x1 || x == x2) continue;
                    auto it = yes[yy + T].find(x);
                    if (it != yes[yy + T].end()) {
                        ans++;
                        trace(x1, y1, x2, y2, x, yy);
                    }
                }
                continue;
            }
            for (int y = -T; y <= T; y++) {
                if (y == y1 || y == y2) continue;
                int yy = y + T;
                if (yes[yy].empty()) continue;
                int x = (y1 * x2 - x1 * y2) + y * (x1 - x2);
                if (x % (y1 - y2)) continue;
                x /= (y1 - y2);
                auto it = yes[yy].find(x);
                if (it != yes[yy].end()) {
                    ans++;
                    trace(x1, y1, x2, y2, x, y);
                }
            }
        }
    }
    trace(ans);
    ans = ((1LL * n * (n - 1) * (n - 2)) / 6) - ans / 3;
    cout << ans << '\n';
}
