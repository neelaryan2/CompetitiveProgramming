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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int& e : a) cin >> e;
    for (int& e : b) cin >> e;
    int ans = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        int mn = 1 << 9;
        for (int t : b)
            mn = min(mn, a[i] & t);
        mx = max(mx, mn);
    }
    for (int i = 0; i < n; i++) {
        int mn = 1 << 9;
        for (int t : b)
            mn = min(mn, mx | (a[i] & t));
        mx = mn;
        ans = max(ans, mn);
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
        solve(i);
        cout << '\n';
    }
}
