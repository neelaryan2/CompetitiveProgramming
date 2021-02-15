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
    vector<int> t(n), d(n), p(n), id(n);
    vector<array<int, 4>> tdp(n);
    int up = 0;
    for (int i = 0; i < n; i++) {
        cin >> tdp[i][1] >> tdp[i][0] >> tdp[i][2];
        tdp[i][3] = i + 1;
        up += tdp[i][1];
    }
    sort(all(tdp));
    for (int i = 0; i < n; i++) {
        t[i] = tdp[i][1];
        d[i] = tdp[i][0];
        p[i] = tdp[i][2];
        id[i] = tdp[i][3];
    }
    int dp[n + 1][up + 1];
    memset(dp, 0, sizeof dp);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= up; j++) {
            int& v = dp[i + 1][j];
            v = max(v, dp[i][j]);
            if (t[i] <= j && j < d[i])
                v = max(v, p[i] + dp[i][j - t[i]]);
        }
    }
    int fin = 0;
    for (int i = 0; i <= up; i++)
        fin = max(fin, dp[n][i]);

    trace(fin);

    vector<int> ans;
    for (int i = 0; i <= up; i++) {
        if (dp[n][i] == fin) {
            int v = n;
            while (v > 0) {
                if (dp[v][i] > dp[v - 1][i]) {
                    v--;
                    ans.eb(id[v]);
                    i -= t[v];
                } else
                    v--;
            }
            break;
        }
    }
    reverse(all(ans));

    cout << fin << '\n';
    cout << ans.size() << '\n';
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