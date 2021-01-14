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

vector<int> par, xp, lazy;
vector<vi> vec;

void makeset(int v) {
    par[v] = v;
    vec[v] = {v};
    xp[v] = 0;
    lazy[v] = 0;
}
int root(int a) {
    int _a = a;
    while (a != par[a]) a = par[a];
    par[_a] = a;
    return a;
}
void unite(int a, int b) {
    a = root(a);
    b = root(b);
    if (a == b) return;

    if (vec[a].size() < vec[b].size())
        swap(a, b);

    while (!vec[b].empty()) {
        int x = vec[b].back();
        vec[b].pop_back();
        xp[x] += lazy[b] - lazy[a];
        vec[a].eb(x);
    }

    lazy[b] = 0;
    par[b] = a;
}

void solve(int test) {
    int n, m;
    cin >> n >> m;
    vec.resize(n);
    par.resize(n);
    xp.resize(n);
    lazy.resize(n);

    for (int i = 0; i < n; i++)
        makeset(i);

    while (m--) {
        string t;
        int a, b;
        cin >> t;
        if (t == "join") {
            cin >> a >> b;
            a--, b--;
            unite(a, b);
        }
        if (t == "add") {
            cin >> a >> b;
            a = root(a - 1);
            lazy[a] += b;
        }
        if (t == "get") {
            cin >> a, a--;
            cout << lazy[root(a)] + xp[a] << '\n';
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
