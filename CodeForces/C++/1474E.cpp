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

    vector<int> p(n);
    vector<pii> idx;
    iota(all(p), 0);
    ll ans = 0;

    auto upd = [&](int i, int j) {
        swap(p[i], p[j]);
        assert(p[j] == i);
        if (p[j] != i) swap(i, j);
        idx.eb(i + 1, j + 1);
        ans += 1LL * (i - j) * (i - j);
    };

    upd(0, n - 1);
    for (int i = 1; i < n / 2; i++) {
        upd(i, n - 1);
        upd(n - i - 1, 0);
    }
    if (n & 1) upd(n / 2, 0);
    reverse(all(idx));

    cout << ans << '\n';
    for (int i : p)
        cout << (i + 1) << ' ';
    cout << '\n';
    cout << (n - 1) << '\n';
    for (pii t : idx)
        cout << t.fi << ' ' << t.se << '\n';
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
    }
}
