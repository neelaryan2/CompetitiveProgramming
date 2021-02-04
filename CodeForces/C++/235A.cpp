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

ll solve(int test) {
    int n;
    cin >> n;
    if (n <= 2) return n;
    ll ans = 1LL * n * (n - 1) * (n - 2);
    if (n & 1) return ans;
    ans /= 2;
    if (n % 3)
        ans = max(ans, 1LL * (n - 3) * (n - 1) * n);
    ans = max(ans, 1LL * (n - 3) * (n - 1) * (n - 2));
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << solve(i) << '\n';
    }
}
