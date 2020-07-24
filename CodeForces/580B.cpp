#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using ld = long double;
using pii = pair<int, ll>;
using vi = vector<int>;
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, d;
    cin >> n >> d;
    vector<pii> v(n);
    for (pii& p : v)
        cin >> p.fi >> p.se;
    v.eb(-1, 0);
    sort(all(v));
    for (int i = 0; i < n; i++)
        v[i + 1].se += v[i].se;
    ll ans = -1;
    for (int i = 1; i <= n; i++) {
        int j = lb(all(v), mp(v[i].fi + d, -1LL)) - v.begin();
        ans = max(ans, v[j - 1].se - v[i - 1].se);
    }
    cout << ans << '\n';
}
