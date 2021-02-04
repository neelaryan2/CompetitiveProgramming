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
    vector<int> a(n), inv(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        inv[--a[i]] = i;
    }
    auto get = [&](int i) {
        if (i < n / 2) return i + n / 2;
        return i - n / 2;
    };
    auto check = [&](int i, int j) {
        return 2 * abs(i - j) >= n;
    };
    vector<pii> ans;
    trace(a, inv);
    auto add = [&](int i, int j) {
        assert(check(i, j));
        ans.eb(i, j);
        swap(a[i], a[j]);
        inv[a[i]] = i;
        inv[a[j]] = j;
        trace(a, inv);
    };
    for (int i = 0; i < n; i++) {
        if (a[i] == i) continue;
        int j = inv[i];
        int ii = get(i), jj = get(j);
        // trace(i, j, ii, jj);
        if (check(i, j)) {
            add(i, j);
        } else if (check(ii, j)) {
            add(i, ii);
            add(ii, j);
            add(ii, i);
        } else if (check(i, jj)) {
            add(i, jj);
            add(jj, j);
            add(jj, i);
        } else {
            assert(check(ii, jj));
            add(i, ii);
            add(ii, jj);
            add(jj, j);
            add(jj, ii);
            add(ii, i);
        }
    }
    cout << ans.size() << '\n';
    for (pii p : ans)
        cout << p.fi + 1 << ' ' << p.se + 1 << '\n';
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
