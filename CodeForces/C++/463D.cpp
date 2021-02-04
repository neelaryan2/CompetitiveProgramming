/* Author - Neel Aryan (@neelaryan2) */
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<vi> p(k, vi(n));
    vector<vi> pos(k, vi(n));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> p[i][j];
            p[i][j]--;
            pos[i][p[i][j]] = j;
        }
    }
    vector<int> dp(n, 0);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int& res = dp[i];
        for (int j = 0; j < i; j++) {
            bool flag = true;
            for (int t = 1; t < k; t++) {
                if (pos[t][p[0][j]] >= pos[t][p[0][i]])
                    flag = false;
            }
            if (flag) res = max(res, dp[j]);
        }
        ans = max(ans, ++res);
    }
    cout << ans << '\n';
}
