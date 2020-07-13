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
const int inf = INT_MAX;
int n, k;
vector<vi> p, dp;
int C(int i, int j) {
    return (p[j][j] + p[i][i] - p[i][j] - p[j][i]) / 2;
}
void compute(int x, int l, int r, int optl, int optr) {
    if (l > r) return;
    int mid = (l + r) >> 1;
    pair<int, int> best = {inf, -1};
    for (int c = max(x, optl); c <= min(mid, optr); c++)
        best = min(best, {dp[x - 1][c - 1] + C(c, mid + 1), c});
    dp[x][mid] = best.first;
    int opt = best.second;
    compute(x, l, mid - 1, optl, opt);
    compute(x, mid + 1, r, opt, optr);
}
char buffer[10000];
int main() {
    scanf("%d %d\n", &n, &k);
    p.assign(n + 1, vi(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        gets(buffer);
        for (int j = 1; j <= n; j++) {
            p[i][j] = buffer[2 * (j - 1)] - '0';
            p[i][j] += p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
        }
    }
    dp.assign(k, vi(n, 0));
    for (int i = 0; i < n; i++)
        dp[0][i] = C(0, i + 1);
    for (int i = 1; i < k; i++)
        compute(i, 0, n - 1, 0, n - 1);
    trace(dp);
    int ans = dp[k - 1][n - 1];
    cout << ans << '\n';
}
