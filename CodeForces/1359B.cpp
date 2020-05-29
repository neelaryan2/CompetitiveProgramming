/* Author - Neel Aryan (@neelaryan2) */
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
auto RLE(string str) {
    int n = str.length();
    vector<pair<char, int>> vec;
    for (int i = 0; i < n; i++) {
        int count = 1;
        while (i < n - 1 && str[i] == str[i + 1]) {
            count++;
            i++;
        }
        vec.pb(mp(str[i], count));
    }
    return vec;
}
void solve() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    y = min(y, 2 * x);
    vector<vi> g(n, vi(m, 0));
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        auto v = RLE(s);
        for (auto p : v) {
            if (p.fi == '.') {
                ans += 1LL*(p.se / 2) * y + (p.se % 2) * x;
            }
        }
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
