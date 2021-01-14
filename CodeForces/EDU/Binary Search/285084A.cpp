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
    int n, k;
    cin >> n >> k;
    vector<ll> l(n), r(n);
    for (int i = 0; i < n; i++)
        cin >> l[i] >> r[i];

    auto calc = [&](ll x) {
        // calc(x) <= k
        // calc(x+1) > k
        ll have = 0;
        for (int i = 0; i < n; i++)
            have += min(max(x - l[i], 0LL), r[i] - l[i] + 1);
        return have <= k;
    };

    ll lo = -2e9, hi = 2e9 + 1, mid;
    while (lo < hi - 1) {
        mid = (lo + hi) / 2;
        if (calc(mid))
            lo = mid;
        else
            hi = mid;
    }
    cout << lo << '\n';
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
