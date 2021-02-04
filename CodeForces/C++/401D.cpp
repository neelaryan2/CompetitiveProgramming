#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<ll>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
const int B = 18;
const int N = 1 << B;
const int M = 100;
// ll dp[N][M];
vector<vi> dp;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m;
    cin >> n >> m;
    // for (int i = 0; i < N; i++)
    //     for (int j = 0; j < M; j++)
    //         dp[i][j] = 0;
    ll pw = 1;
    vector<int> dig, cnt(10, 0), rem;
    while (n) {
        cnt[n % 10]++;
        dig.pb(n % 10);
        rem.pb(pw % m);
        n /= 10, pw *= 10;
    }
    n = (int)dig.size();
    dp.assign(1 << n, vi(m, 0));
    vector<int> vec(1 << n);
    iota(all(vec), 0);
    sort(all(vec), [](int i, int j) {
        int a = __builtin_popcount(i);
        int b = __builtin_popcount(j);
        return a < b;
    });
    dp[0][0] = 1;
    for (int i : vec) {
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) {
                int ni = i ^ (1 << j);
                if (!dig[j] && !ni) continue;
                for (int l = 0; l < m; l++) {
                    int nl = (10 * l + dig[j]) % m;
                    dp[i][nl] += dp[ni][l];
                }
            }
        }
    }
    vector<ll> fac(20, 1);
    for (int i = 1; i < 20; i++)
        fac[i] = i * fac[i - 1];
    ll ans = dp[(1 << n) - 1][0];
    for (int i = 0; i < 10; i++)
        ans /= fac[cnt[i]];
    cout << ans << '\n';
}
