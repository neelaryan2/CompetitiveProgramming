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
const int inf = 1e9;
int sum(ll x) {
    int s = 0;
    for (; x; x /= 10) s += x % 10;
    return s;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> ans;
    for (int s = 1; s <= 81; s++) {
        ll cs = 1;
        for (int _ = 0; _ < a; _++)
            cs *= s;
        cs = b * cs + c;
        if (sum(cs) == s && cs < inf)
            ans.eb(cs);
    }
    sort(all(ans));
    cout << ans.size() << '\n';
    for (int i : ans) cout << i << ' ';
    cout << '\n';
}
