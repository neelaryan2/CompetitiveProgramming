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

vector<int> siz, par, mx, mn;
void makeset(int v) {
    par[v] = v;
    mn[v] = v + 1;
    mx[v] = v + 1;
    siz[v] = 1;
}
int root(int a) {
    if (par[a] == -1) par[a] = a;
    int _a = a;
    while (a != par[a]) a = par[a];
    par[_a] = a;
    return a;
}
void unite(int a, int b) {
    a = root(a);
    b = root(b);
    if (a == b) return;
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b];
    mx[a] = max(mx[a], mx[b]);
    mn[a] = min(mn[a], mn[b]);
    par[b] = a;
}

void solve(int test) {
    int n, m;
    cin >> n >> m;
    par.resize(n);
    siz.resize(n);
    mn.resize(n);
    mx.resize(n);

    for (int i = 0; i < n; i++)
        makeset(i);

    while (m--) {
        string t;
        int a, b;
        cin >> t;
        if (t == "union") {
            cin >> a >> b;
            a--, b--;
            unite(a, b);
        }
        if (t == "get") {
            cin >> a;
            a = root(a - 1);
            cout << mn[a] << ' ';
            cout << mx[a] << ' ';
            cout << siz[a] << '\n';
        }
    }
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
