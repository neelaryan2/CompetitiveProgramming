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

const int N = 31;
const ll inf = 1e18;

void solve(int test) {
    int n[3];
    for (int i = 0; i < 3; i++)
        cin >> n[i];
    
    vector<ll> sum(3, 0);
    vector<int> a[3], mn(3, 1e9 + 7);

    ll tot = 0, ans = -inf;

    for (int i = 0; i < 3; i++) {
        a[i].resize(n[i]);
        for (int j = 0; j < n[i]; j++) {
            cin >> a[i][j];
            sum[i] += a[i][j];
            mn[i] = min(mn[i], a[i][j]);
        }
        tot += sum[i];
    }

    for (int i = 0; i < 3; i++) {
        ll sub = 0;
        for (int j = 0; j < 3; j++) {
            if (j == i) continue;
            sub += mn[j];
        }
        ans = max(ans, tot - 2 * sum[i]);
        ans = max(ans, tot - 2 * sub);
    }
    cout << ans;
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
        cout << '\n';
    }
}
