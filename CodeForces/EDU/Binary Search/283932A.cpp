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
    int w, h, n;
    cin >> w >> h >> n;
    auto good = [&](ll x) {
        return (x / w) * (x / h) >= n;
    };
    ll l = 0, r = 1;
    while (!good(r))
        r <<= 1;
    while (l < r - 1) {
        ll mid = (l + r) / 2;
        if (good(mid))
            r = mid;
        else
            l = mid;
    }
    cout << r << '\n';
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
    }
}
