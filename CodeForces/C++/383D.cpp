#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
const int mxS = 1e4 + 1;
const int mod = 1e9 + 7;
int dp[2][2 * mxS];
inline void add(int& a, int b) {
    a = (a + b) % mod;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, f = 0;
    cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    memset(dp, 0, sizeof(dp));
    int ans = 0;
    for (int i = 0; i < n; i++) {
        add(ans, dp[f][mxS]);
        int cur = a[i];
        add(dp[f][mxS], 1);
        for (int j = 0; j < 2 * mxS; j++) {
            if (j >= cur) add(dp[f ^ 1][j - cur], dp[f][j]);
            if (j + cur < 2 * mxS) add(dp[f ^ 1][j + cur], dp[f][j]);
        }
        memset(dp[f], 0, sizeof(dp[f]));
        f ^= 1;
    }
    add(ans, dp[f][mxS]);
    cout << ans << '\n';
}
