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
const int N = 31;
const ll inf = 1e18;
void solve(int test) {
    ll n, m;
    cin >> n >> m;
    if (n <= m) {
        cout << n;
        return;
    }
    n -= m;
    ll lo = 0, hi = 2e9;
    ll cur, mid;
    while (lo < hi - 1) {
        mid = (lo + hi) / 2;
        cur = (mid * (mid + 1)) / 2;
        if (cur >= n)
            hi = mid;
        else
            lo = mid;
    }
    cout << hi + m;
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
