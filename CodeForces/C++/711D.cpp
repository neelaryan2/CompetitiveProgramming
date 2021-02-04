/* Author - Neel Aryan (@neelaryan2) */
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

const int kMod = 1e9 + 7;
vector<int> vis, num, nxt;
int T = 0, cyc = 0;
void dfs(int v, int p = -1) {
    vis[v] = 1;
    num[v] = T++;
    int u = nxt[v];
    if (vis[u]) {
        if (vis[u] == 1)
            cyc = num[v] - num[u] + 1;
    } else
        dfs(u);
    vis[v] = 2;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vis.assign(n, 0);
    num.resize(n);
    nxt.resize(n);
    for (int& e : nxt) cin >> e, e--;
    int tot = n, ans = 1;
    vector<int> pw(n + 1, 1);
    for (int i = 1; i <= n; i++)
        pw[i] = (pw[i - 1] * 2LL) % kMod;
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        cyc = 0;
        dfs(i), tot -= cyc;
        if(cyc < 2) continue;
        ans = (1LL * ans * (pw[cyc] - 2)) % kMod;
    }
    ans = (1LL * ans * pw[tot]) % kMod;
    cout << ans << '\n';
}
