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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    scanf("%d %d\n", &n, &m);
    char g[n][m + 1];
    int righ[n][m + 1];
    memset(righ, 0, sizeof righ);
    for (int i = 0; i < n; i++)
        gets(g[i]);
    for (int i = 0; i < n; i++)
        for (int j = m - 1; j >= 0; j--)
            if (g[i][j] == '1')
                righ[i][j] = 1 + righ[i][j + 1];
    int ans = 0;
    for (int j = 0; j < m; j++) {
        vector<int> cnt(m + 1, 0);
        for (int i = 0; i < n; i++)
            cnt[righ[i][j]]++;
        for (int i = m - 1; i >= 0; i--)
            cnt[i] += cnt[i + 1];
        for (int i = 1; i <= m; i++)
            ans = max(ans, cnt[i] * i);
    }
    cout << ans << '\n';
}
