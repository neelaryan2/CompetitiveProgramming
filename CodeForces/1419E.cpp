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
    int m = n;
    vector<pii> pf;
    for (int i = 2; i * i <= m; i++) {
        if (m % i) continue;
        int cnt = 0;
        while (m % i == 0) {
            m /= i;
            cnt++;
        }
        pf.eb(i, cnt);
    }
    if (m != 1) pf.eb(m, 1);
    int k = pf.size();
    if (k == 1) {
        int p = pf[0].fi, c = pf[0].se;
        while (1) {
            cout << p << ' ';
            if (--c == 0) break;
            p *= pf[0].fi;
        }
        cout << '\n';
        cout << 0;
        return;
    }
    if (k == 2) {
        if (pf[0].se == 1 && pf[1].se == 1) {
            int p1 = pf[0].fi, p2 = pf[1].fi;
            cout << p1 << ' ' << n << ' ' << p2 << '\n';
            cout << 1;
            return;
        }
    }
    map<int, vi> bat;
    for (int i = 2; i * i <= n; i++) {
        if (n % i) continue;
        int d1 = i, d2 = n / i;
        for (int j = 0; j < k; j++) {
            int p = pf[j].fi;
            if (d1 % p == 0) {
                bat[p].pb(d1);
                break;
            }
        }
        if (d1 == d2) break;
        for (int j = 0; j < k; j++) {
            int p = pf[j].fi;
            if (d2 % p == 0) {
                bat[p].pb(d2);
                break;
            }
        }
    }
    vector<int> ans(1);
    ans[0] = n;
    trace(pf);
    for (int i = 0; i < k; i++) {
        int p = pf[i].fi;
        int pn = pf[(i + 1) % k].fi;
        int last = -1;
        for (int e : bat[p]) {
            if (e % pn == 0) {
                last = e;
                break;
            }
        }
        assert(i == k - 1 || last != -1);
        for (int e : bat[p]) {
            if (e == last) continue;
            ans.eb(e);
        }
        if (i != k - 1) ans.eb(last);
    }
    for (int e : ans) cout << e << ' ';
    cout << '\n';
    cout << 0;
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
