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
    int n, m;
    cin >> n >> m;
    vector<int> col(1e5 + 5, 0);
    vector<set<int>> ans(1e5 + 5);
    for (int i = 1; i <= n; i++)
        cin >> col[i];
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        if (col[u] == col[v]) continue;
        ans[col[u]].insert(col[v]);
        ans[col[v]].insert(col[u]);
    }
    int ind = 1e9, mx = 0;
    for (int i = 1; i <= n; i++) {
        int sz = ans[col[i]].size();
        if (sz < mx) continue;
        if (sz == mx && col[i] >= ind) continue;
        mx = sz, ind = col[i];
    }
    cout << ind << '\n';
}
