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
    int a, b, c;
    cin >> a >> b >> c;
    int ans = inf, aa, bb, cc;
    for (int fa = 1; fa <= 2 * a; fa++) {
        for (int fb = fa; fb <= 2 * b; fb += fa) {
            for (int t : {0, 1}) {
                int fc = c - c % fb;
                if (t || fc == 0) fc += fb;
                int cur = abs(a - fa) + abs(b - fb) + abs(c - fc);
                if (cur < ans) {
                    ans = cur;
                    aa = fa, bb = fb, cc = fc;
                }
            }
        }
    }
    cout << ans << '\n';
    cout << aa << ' ' << bb << ' ' << cc;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve(i);
        cout << '\n';
    }
}
