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
const int inf = 1e9 + 10;
int get(vector<int> a, int k) {
    for (int& e : a)
        if (e == -1) e = k;
    int m = -1;
    for (int i = 1; i < a.size(); i++)
        m = max(m, abs(a[i] - a[i - 1]));
    return m;
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    int mn = inf, mx = -inf;
    for (int i = 0; i < n; i++) {
        if (a[i] == -1) continue;
        bool b1 = (i + 1 < n && a[i + 1] == -1);
        bool b2 = (i > 0 && a[i - 1] == -1);
        if (b1 || b2) {
            mn = min(mn, a[i]);
            mx = max(mx, a[i]);
        }
    }
    if (mn == inf) {
        cout << "0 1\n";
        return;
    }
    int k1 = (mn + mx) / 2;
    int k2 = 1 + (mn + mx - 1) / 2;
    int k = (get(a, k2) < get(a, k1)) ? k2 : k1;
    cout << get(a, k) << ' ' << k << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}