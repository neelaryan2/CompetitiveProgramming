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

vector<int> siz[2], par[2];
int root(int a, int w) {
    if (par[w][a] == -1) par[w][a] = a;
    int _a = a;
    while (a != par[w][a]) a = par[w][a];
    par[w][_a] = a;
    return a;
}
void add(int a, int b, int w) {
    a = root(a, w);
    b = root(b, w);
    if (a == b) return;
    if (siz[w][a] < siz[w][b]) swap(a, b);
    siz[w][a] += siz[w][b];
    par[w][b] = a;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int w : {0, 1}) {
        siz[w].assign(n, 1);
        par[w].assign(n, -1);
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        add(u, v, w);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int r0 = root(i, 0), s0 = siz[0][r0];
        int r1 = root(i, 1), s1 = siz[1][r1];
        if (r0 == i) ans += 1LL * s0 * (s0 - 1);
        if (r1 == i) ans += 1LL * s1 * (s1 - 1);
        ans += 1LL * (s0 - 1) * (s1 - 1);
    }
    cout << ans << '\n';
}
