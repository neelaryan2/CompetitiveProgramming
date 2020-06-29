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

void solve(int test) {
    int n;
    cin >> n;
    vector<ppi> seg(n);
    for (int i = 0; i < n; i++) {
        pii p;
        cin >> p.fi >> p.se;
        seg[i] = mp(p, i);
    }
    sort(all(seg));
    int r1 = -1, r2 = -1;
    vector<int> ans(n);
    for (ppi p : seg) {
        int l = p.fi.fi, r = p.fi.se;
        if (l > max(r1, r2)) {
            if (r1 == -1) {
                r1 = r;
                ans[p.se] = 1;
            } else {
                r2 = r;
                ans[p.se] = 2;
            }
        } else if (l <= r1) {
            r1 = max(r1, r);
            ans[p.se] = 1;
        } else if (l <= r2) {
            r2 = max(r2, r);
            ans[p.se] = 2;
        } else {
            cout << "-1\n";
            return;
        }
    }
    if (r1 == -1 || r2 == -1) {
        cout << "-1\n";
        return;
    }
    for (int i : ans) cout << i << ' ';
    cout << '\n';
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
