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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for (int& e : a) cin >> e;
    for (int& e : b) cin >> e;
    vector<int> v;
    v.eb(b[0]);
    for (int i = 1; i < n; i++) {
        v.eb(a[i]);
        v.eb(b[i]);
    }
    v.eb(a[0]);
    ld ans = 0, w = m;
    for (int i : v) {
        if (i == 1) {
            cout << "-1\n";
            return 0;
        }
        ld c = w / (i - 1);
        w += c, ans += c;
    }
    cout << fixed << setprecision(10) << ans << '\n';
}
