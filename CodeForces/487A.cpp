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
#define rall(v) (v).rbegin(), (v).rend()

const int inf = 1e9 + 7;

void solve(int test) {
    int hp_y, atk_y, def_y;
    int hp_m, atk_m, def_m;
    int h, a, d;
    cin >> hp_y >> atk_y >> def_y;
    cin >> hp_m >> atk_m >> def_m;
    cin >> h >> a >> d;
    if (def_y > atk_m) {
        cout << max(0, a * (def_m - atk_y + 1));
        return;
    }
    if (atk_y > hp_m + def_m) {
        cout << 0;
        return;
    }

    int ans = inf, _atk_y = atk_y;
    for (int nd = 0; def_y <= atk_m; def_y++, nd++) {
        atk_y = _atk_y;
        for (int na = 0; atk_y <= hp_m + def_m; atk_y++, na++) {
            if (atk_y <= def_m) continue;
            int hp_y_new = (hp_m + atk_y - def_m - 1) / (atk_y - def_m);
            hp_y_new *= max(0, atk_m - def_y);
            int nh = max(0, hp_y_new - hp_y + 1);
            ans = min(ans, na * a + nd * d + nh * h);
        }
    }
    cout << ans;
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
