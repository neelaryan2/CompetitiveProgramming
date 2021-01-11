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
using ppi = pair<pii, int>;
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
    ll n, C;
    cin >> n >> C;
    vector<ppi> seg(n);
    vector<int> s;
    for (int i = 0; i < n; i++) {
        ppi p;
        cin >> p.fi.fi >> p.fi.se >> p.se;
        p.fi.se++;
        seg[i] = p;
        s.eb(p.fi.fi);
        s.eb(p.fi.se);
    }
    sort(all(s));
    int k = unique(all(s)) - s.begin();
    s.resize(k);

    vector<ll> sum(k, 0);
    for (int i = 0; i < n; i++) {
        ppi p = seg[i];
        int l = lb(all(s), p.fi.fi) - s.begin();
        int r = lb(all(s), p.fi.se) - s.begin();
        sum[l] += p.se;
        sum[r] -= p.se;
    }
    for (int i = 1; i < k; i++)
        sum[i] += sum[i - 1];
    ll ans = 0;
    for (int i = 0; i < k - 1; i++) {
        sum[i] = min(sum[i], C);
        ans += (s[i + 1] - s[i]) * sum[i];
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
