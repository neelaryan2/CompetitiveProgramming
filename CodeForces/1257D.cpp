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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    int m;
    cin >> m;
    vector<pii> h(m);
    for (pii& p : h) cin >> p.fi >> p.se;
    sort(rall(h));
    int prv = 0;
    vector<int> bst(n + 1);
    for (int i = 0; i < m; i++) {
        while (prv <= h[i].se)
            bst[prv++] = h[i].fi;
    }
    trace(bst);
    int ans = 0;
    for (int i = 0; i < n;) {
        if (a[i] > bst[1]) {
            cout << -1;
            return;
        }
        int mx = a[i], j = 1;
        while (mx <= bst[j]) {
            trace(mx, bst[j]);
            mx = max(mx, a[++i]);
            j++;
        }
        trace(mx, bst);
        ans++;
    }
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
        cout << '\n';
    }
}
