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
const int inf = 1e9 + 7;
void solve(int test) {
    int n, delta = 0;
    cin >> n;
    int hi = inf, lo = -inf;
    int base = 1900;
    for (int i = 0; i < n; i++) {
        int c, d;
        cin >> c >> d;
        if (d == 1)
            lo = max(lo, base - delta);
        else
            hi = min(hi, base - delta - 1);
        delta += c;
    }
    if (hi == inf)
        cout << "Infinity";
    else if (lo > hi)
        cout << "Impossible";
    else
        cout << hi + delta;
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
