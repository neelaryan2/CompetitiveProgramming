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
    int n, k;
    cin >> n >> k;
    vector<int> t[2][2];
    for (int i = 0; i < n; i++) {
        int tt, a, b;
        cin >> tt >> a >> b;
        t[a][b].eb(tt);
    }
    vector<ll> p[2][2];
    for (int i : {0, 1}) {
        for (int j : {0, 1}) {
            sort(all(t[i][j]));
            int c = t[i][j].size();
            p[i][j].assign(c + 1, 0);
            for (int v = 0; v < c; v++)
                p[i][j][v + 1] = p[i][j][v] + t[i][j][v];
        }
    }
    ll ans = LLONG_MAX;
    for (int i = 0; i < p[1][1].size(); i++) {
        if (k - i >= p[0][1].size()) continue;
        if (k - i >= p[1][0].size()) continue;
        ans = min(ans, p[1][1][i] + p[0][1][k - i] + p[1][0][k - i]);
    }
    if (ans == LLONG_MAX) ans = -1;
    cout << ans << '\n';
}
