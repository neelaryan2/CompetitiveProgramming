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
#define rall(v) (v).rbegin(), (v).rend()

const int inf = 1e9 + 7;

vector<int> siz, par, mn, mx;
int root(int a) {
    int _a = a;
    while (a != par[a]) a = par[a];
    par[_a] = a;
    return a;
}
int add(int a, int b) {
    a = root(a);
    b = root(b);
    if (a == b) return -1;
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b];
    par[b] = a;
    mx[a] = max(mx[a], mx[b]);
    mn[a] = min(mn[a], mn[b]);
    return a;
}
void solve(int test) {
    int n, m;
    cin >> n >> m;
    par.resize(n);
    siz.resize(n);
    mx.resize(n);
    mn.resize(n);
    for (int i = 0; i < n; i++) {
        siz[i] = 1;
        par[i] = i;
        mn[i] = i;
        mx[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        add(u, v);
    }
    vector<int> roots;
    for (int i = 0; i < n; i++)
        if (root(i) == i) roots.eb(i);

    sort(all(roots), [&](int i, int j) {
        return mn[i] < mn[j];
    });

    int ans = 0;
    for (int i = 0; i < roots.size(); i++) {
        int v = roots[i];
        int rnge = mx[v] - mn[v] + 1;
        while (rnge != siz[v]) {
            v = add(v, roots[++i]);
            rnge = mx[v] - mn[v] + 1;
            ans++;
        }
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve(i);
        cout << '\n';
    }
}
