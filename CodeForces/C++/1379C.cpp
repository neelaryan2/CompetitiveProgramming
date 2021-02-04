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
    ll n, m, ind = -1;
    cin >> n >> m;
    vector<pii> v(m);
    for (pii& p : v) cin >> p.fi >> p.se;
    sort(all(v));
    vector<ll> p(m + 1, 0);
    for (int i = 0; i < m; i++)
        p[i + 1] = p[i] + v[i].fi;
    ll ans = -1, cur;
    for (int i = 0; i < m; i++) {
        int a = v[i].fi, b = v[i].se;
        int j = ub(all(v), mp(b, -1)) - v.begin();
        cur = n * b;
        if (j > i) {
            j = max((ll)j, m - n + 1);
            cur += p[m] - p[j] + a - (m - j + 1) * b;
        } else {
            j = max((ll)j, m - n);
            cur += p[m] - p[j] - (m - j) * b;
        }
        ans = max(ans, cur);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
