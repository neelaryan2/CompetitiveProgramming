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
    int m, n;
    cin >> m >> n;
    vector<ll> t(n), z(n), y(n);
    for (int i = 0; i < n; i++)
        cin >> t[i] >> z[i] >> y[i];

    vector<ll> ans(n);
    ll have;
    auto good = [&](ll tx) {
        have = 0;
        for (int i = 0; i < n; i++) {
            ll cur = t[i] * z[i] + y[i];
            ans[i] = (tx / cur) * z[i];
            ans[i] += min((tx % cur) / t[i], z[i]);
            have += ans[i];
        }
        return have >= m;
    };

    ll l = -1, r = 1e10;
    while (l < r - 1) {
        ll mid = l + (r - l) / 2;
        if (good(mid))
            r = mid;
        else
            l = mid;
    }
    good(r);
    trace(have, ans);
    int ptr = 0;
    while (ptr < n && have > m) {
        int tmp = min(have - m, ans[ptr]);
        ans[ptr++] -= tmp;
        have -= tmp;
    }

    cout << r << '\n';
    for (ll i : ans)
        cout << i << ' ';
    cout << '\n';
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
