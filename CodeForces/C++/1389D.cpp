#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using ld = long double;
using pii = pair<ll, ll>;
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
    ll n, k;
    cin >> n >> k;
    pii p1, p2;
    cin >> p1.fi >> p1.se;
    cin >> p2.fi >> p2.se;
    if (p1 > p2) swap(p1, p2);
    ll d0, d1, init;
    if (p2.se <= p1.se) {
        init = p2.se - p2.fi, d0 = 0;
        d1 = p1.se - p2.se + p2.fi - p1.fi;
    } else if (p2.fi <= p1.se) {
        init = p1.se - p2.fi, d0 = 0;
        d1 = p2.se - p1.se + p2.fi - p1.fi;
    } else {
        d0 = p2.fi - p1.se, init = 0;
        d1 = p2.se - p1.fi;
    }
    ll I = init * n;
    trace(test);
    trace(p1, p2);
    trace(d0, d1, I, k);
    ll ans = LLONG_MAX, res = 0;
    for (int i = 0; i < n; i++) {
        if (k <= I) break;
        ll need = min(k - I, d1);
        res += d0 + need, I += need;
        ans = min(ans, res + 2 * max(k - I, 0LL));
    }
    if (ans == LLONG_MAX) ans = 0;
    cout << ans;
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
        cout << "\n";
    }
}
