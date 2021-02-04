#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ppi = pair<int, pii>;
using vpi = vector<pii>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define runtime() (int)(1000 * ((double)clock()) / CLOCKS_PER_SEC)

const int kMod = 1e9 + 7;
using vi = vector<int>;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll R, G, val = 0, n = 0;
    cin >> R >> G;
    while (val <= R + G) val += ++n;
    n--;
    vector<vi> dp(2, vi(R + 1, 0));
    dp[0][0] = 1;
    int cur = 1;
    for (int i = 1; i <= n; i++) {
        int tmp = (i * (i + 1)) / 2;
        for (int r = 0; r <= R; r++) {
            int g = tmp - r, res = 0;
            if (r >= i) res = res + dp[cur ^ 1][r - i];
            if (g <= G) res = res + dp[cur ^ 1][r];
            dp[cur][r] = res % kMod;
        }
        cur ^= 1;
    }
    cur ^= 1;
    int ans = 0;
    for (int r = 0; r <= R; r++)
        ans = (ans + dp[cur][r]) % kMod;
    cerr << runtime() << '\n';
    cout << ans << '\n';
}