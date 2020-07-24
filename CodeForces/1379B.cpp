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
    ll l, r, m;
    cin >> l >> r >> m;
    for (ll i = l; i <= r; i++) {
        ll q = m / i;
        int d1 = m - i * q;
        int d2 = m - i * (q + 1);
        if (q != 0 && l - r <= d1 && d1 <= r - l) {
            cout << i << ' ' << l + d1 << ' ' << l << '\n';
            return;
        }
        if (l - r <= d2 && d2 <= r - l) {
            cout << i << ' ' << r + d2 << ' ' << r << '\n';
            return;
        }
    }
    assert(false);
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
