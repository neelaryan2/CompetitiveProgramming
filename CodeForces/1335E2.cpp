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
const int alph = 200;
void solve() {
    int n;
    cin >> n;
    vector<vi> a(alph);
    vector<vi> cnt(alph, vi(n + 1, 0));
    for (int i = 0, e; i < n; i++) {
        cin >> e, e--;
        a[e].pb(i);
        for (int j = 0; j < alph; j++)
            cnt[j][i + 1] = cnt[j][i] + (e == j);
    }
    int ans = 0;
    trace(a);
    for (int i = 0; i < alph; i++) {
        int k = a[i].size();
        ans = max(ans, k);
        if (k == 0) continue;
        for (int l = 0, r = k - 1; l < r; l++, r--) {
            for (int j = 0; j < alph; j++) {
                if (j == i) continue;
                int cur = cnt[j][a[i][r] + 1] - cnt[j][a[i][l]];
                if (cur == 0) continue;
                trace(i, j, cur);
                ans = max(ans, 2 * l + 2 + cur);
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
