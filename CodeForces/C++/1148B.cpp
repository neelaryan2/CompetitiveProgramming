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
void solve(int test) {
    int n, m, ta, tb, k;
    cin >> n >> m >> ta >> tb >> k;
    vector<int> a(n), b(m);
    for (int& e : a) cin >> e;
    for (int& e : b) cin >> e;
    int ans = -1;
    if (k >= n) {
        cout << -1;
        return;
    }
    for (int i = 0; i <= k; i++) {
        int j = lb(all(b), a[i] + ta) - b.begin();
        j += k - i;
        if (j >= m) {
            cout << -1;
            return;
        }
        ans = max(ans, b[j] + tb);
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
        cout << "\n";
    }
}
