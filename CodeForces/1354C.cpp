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
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
const ld pi = 3.141592653589793238462643383279;
void solve() {
    int n;
    cin >> n;
    ld ang = pi / (2 * n);
    int f = (n & 1) ? 2 : 1;
    ld ans = cos(ang / f) / sin(ang);
    cout << fixed << setprecision(9) << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
