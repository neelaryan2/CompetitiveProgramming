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
    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(all(a));
    vector<int> ans(n), dp(n + 1, inf), par(n + 1, -1);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 2; j < min(5, n - i); j++) {
            int cur = dp[i] + a[i + j].fi - a[i].fi;
            int nxt = i + j + 1;
            if (dp[nxt] > cur) {
                par[nxt] = i;
                dp[nxt] = cur;
            }
        }
    }
    int ptr = n, cnt = 1;
    while (ptr) {
        for (int i = par[ptr]; i < ptr; i++)
            ans[a[i].se] = cnt;
        ptr = par[ptr], cnt++;
    }
    cout << dp[n] << ' ' << (cnt - 1) << '\n';
    for (int i : ans)
        cout << i << ' ';
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
