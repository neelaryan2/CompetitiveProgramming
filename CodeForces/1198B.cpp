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
    int q;
    cin >> q;
    vector<int> que[3];
    while (q--) {
        int t, p = -1, x;
        cin >> t;
        if (t == 1)
            cin >> p;
        cin >> x;
        que[0].pb(t);
        que[1].pb(--p);
        que[2].pb(x);
    }
    q = que[0].size();
    int mx = -1;
    vector<bool> done(n, false);
    for (int i = q - 1; i >= 0; i--) {
        int t = que[0][i], p = que[1][i], x = que[2][i];
        if (t == 2) {
            mx = max(mx, x);
        } else if (!done[p]) {
            done[p] = true;
            a[p] = max(x, mx);
        }
    }
    for (int i = 0; i < n; i++)
        if (!done[i])
            a[i] = max(a[i], mx);
    for (int& e : a) 
        cout << e << ' ';
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
