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
vector<int> siz, par;
vector<set<int>> nodes;
int ans = 0;
int root(int a) {
    int _a = a;
    while (a != par[a]) a = par[a];
    par[_a] = a;
    return a;
}
void add(int a, int b) {
    a = root(a);
    b = root(b);
    if (a == b) return;
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b];
    par[b] = a;
    for (int i : nodes[b]) {
        for (int c : {-1, 1}) {
            auto it = nodes[a].find(i + c);
            if (it != nodes[a].end()) ans--;
        }
    }
    for (int i : nodes[b]) nodes[a].insert(i);
    nodes[b].clear();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    siz.assign(m, 0);
    par.assign(m, -1);
    nodes.resize(m);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        int& e = a[i];
        cin >> e, e--;
        nodes[e].insert(i);
        siz[e]++;
        par[e] = e;
    }
    for (int i = 1; i < n; i++)
        if (a[i] != a[i - 1]) ans++;
    cout << ans << '\n';
    for (int _ = 1; _ < m; _++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        add(x, y);
        cout << ans << '\n';
    }
}
