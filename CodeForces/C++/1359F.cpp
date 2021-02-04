/* Author - Neel Aryan (@neelaryan2) */
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using ld = double;
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

const ld inf = 1e10;
const int N = 25010;
constexpr ld eps = 1e-9;

int x[N], y[N];
ld dx[N], dy[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ld sp, mag;
        cin >> x[i] >> y[i] >> dx[i] >> dy[i] >> sp;
        mag = sp / sqrtl(dx[i] * dx[i] + dy[i] * dy[i]);
        dx[i] *= mag, dy[i] *= mag;
    }
    ld ans = inf, cur;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ld D = dx[i] * dy[j] - dy[i] * dx[j];
            int dxx = x[j] - x[i], dyy = y[j] - y[i];
            if (abs(D) < eps) {
                if (abs(dyy * dx[i] - dxx * dy[i]) > eps) 
                    continue;
                if (dx[i] * dx[j] < 0) {
                    cur = dxx / (dx[i] - dx[j]);
                    if (cur > 0) ans = min(ans, cur);
                } else {
                    cur = (-dxx) / dx[j];
                    if (cur > 0) ans = min(ans, cur);
                    cur = dxx / dx[i];
                    if (cur > 0) ans = min(ans, cur);
                }
            } else {
                ld t1 = (dxx * dy[j] - dyy * dx[j]) / D;
                ld t2 = (t1 * dx[i] - dxx) / dx[j];
                if (t1 > t2) swap(t1, t2);
                if (t1 > -eps) ans = min(ans, t2);
            }
            trace(i, j, ans);
        }
    }
    if (ans > inf - 1) {
        cout << "No show :(\n";
        return 0;
    }
    cout << fixed << setprecision(15) << ans << '\n';
}
