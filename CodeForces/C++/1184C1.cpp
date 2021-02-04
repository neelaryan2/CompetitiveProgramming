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
    int n;
    cin >> n;
    vector<int> x(4 * n + 1), y(4 * n + 1);
    for (int i = 0; i <= 4 * n; i++)
        cin >> x[i] >> y[i];

    for (int cx = 0; cx < 50; cx++) {
        for (int cy = 0; cy < 50; cy++) {
            for (int l = 1; l <= 50; l++) {
                if (max(cx, cy) + l > 50) break;
                int bad = 0, id = -1;
                for (int i = 0; i <= 4 * n; i++) {
                    if (x[i] == cx || x[i] == cx + l) {
                        if (y[i] < cy || y[i] > cy + l)
                            bad++, id = i;
                    } else if (y[i] == cy || y[i] == cy + l) {
                        if (x[i] < cx || x[i] > cx + l)
                            bad++, id = i;
                    } else {
                        bad++, id = i;
                    }
                }
                if (bad == 1) {
                    cout << x[id] << ' ' << y[id];
                    return;
                }
            }
        }
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
        cout << '\n';
    }
}
