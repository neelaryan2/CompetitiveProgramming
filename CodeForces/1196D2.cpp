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
const string base = "RGB";
const int sz = base.size();
void solve(int test) {
    int n, k, ans = 1e9;
    string s;
    cin >> n >> k >> s;
    int dp[n - k + 1][sz];
    for (int off = 0; off < sz; off++) {
        int cur = 0;
        for (int j = 0; j < k; j++) {
            char c = base[(j + off) % sz];
            if (s[j] != c) cur++;
        }
        dp[0][off] = cur;
        ans = min(ans, cur);
    }
    for (int i = 1; i <= n - k; i++) {
        for (int off = 0; off < sz; off++) {
            int prv = off - 1;
            if (prv < 0) prv += sz;
            int& cur = dp[i][off];
            cur = dp[i - 1][prv];
            cur -= (s[i - 1] != base[prv]);
            cur += (s[i + k - 1] != base[(prv + k) % sz]);
            ans = min(ans, cur);
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
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
