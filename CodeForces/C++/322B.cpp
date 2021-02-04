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
    ll r, g, b;
    cin >> r >> g >> b;
    ll mn = min({r, g, b}), ans = 0;
    for (int i = 0; i < 3; i++) {
        ans = max(ans, i + r / 3 + g / 3 + b / 3);
        if (!mn) break;
        r--, g--, b--, mn--;
    }
    cout << ans << '\n';
}
