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

vector<int> par;
vector<vi> vec;

void makeset(int v) {
    par[v] = v;
    vec[v] = {v};
}
int root(int a) {
    int _a = a;
    while (a != par[a]) a = par[a];
    par[_a] = a;
    return a;
}
void unite(int a, int b) {
    a = root(a), b = root(b);
    if (a == b) return;

    if (vec[a].size() < vec[b].size())
        swap(a, b);

    while (!vec[b].empty()) {
        int x = vec[b].back();
        vec[b].pop_back();
        vec[a].eb(x);
    }
    par[b] = a;
}
bool safe(int i) {
    return root(i) == root(0);
}

void solve(int test) {
    int n, m;
    cin >> n >> m;

    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        if (l[i] != -1) l[i]--;
        if (r[i] != -1) r[i]--;
    }

    vector<int> p(m), h(m);
    for (int i = 0; i < m; i++) {
        cin >> p[i] >> h[i];
        p[i]--;
        if (h[i] == 1) {
            h[i] = l[p[i]];
            l[p[i]] = -1;
        } else {
            h[i] = r[p[i]];
            r[p[i]] = -1;
        }
    }

    par.resize(n);
    vec.resize(n);
    for (int i = 0; i < n; i++)
        makeset(i);

    for (int i = 0; i < n; i++) {
        if (l[i] != -1) unite(i, l[i]);
        if (r[i] != -1) unite(i, r[i]);
    }

    vector<int> ans(n, -1);

    for (int i = m - 1; i >= 0; i--) {
        int u = p[i], v = h[i];
        bool su = safe(u), sv = safe(v);
        if (su && sv) continue;
        if (su || sv) {
            if (!su) swap(u, v);
            for (int j : vec[root(v)])
                ans[j] = i;
        }
        unite(u, v);
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << '\n';
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
    }
}
