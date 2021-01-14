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
using ppi = pair<ll, pii>;
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

const ll inf = 1e11;

struct PersistentDSU {
    int comp;
    stack<vector<int>> states;
    vector<int> siz, par;
    PersistentDSU(int n = 0) {
        comp = n;
        par.resize(n);
        siz.resize(n);
        for (int i = 0; i < n; i++)
            makeset(i);
    }
    void makeset(int a) {
        par[a] = a;
        siz[a] = 1;
    }
    int root(int a) {
        if (par[a] == a) return a;
        return root(par[a]);
    }
    int unite(int a, int b) {
        a = root(a), b = root(b);
        if (a == b) return 0;
        if (siz[a] > siz[b])
            swap(a, b);
        states.push({b, siz[b], a, par[a]});
        siz[b] += siz[a];
        par[a] = b;
        comp--;
        return 1;
    }
    void rollback() {
        if (states.empty()) return;
        vector<int> s = states.top();
        states.pop();
        siz[s[0]] = s[1];
        par[s[2]] = s[3];
        comp++;
    }
};
void solve(int test) {
    int n, m;
    cin >> n >> m;

    PersistentDSU dsu(n);

    stack<int> cnts;
    cnts.push(0);
    for (int i = 1; i <= m; i++) {
        string t;
        cin >> t;
        if (t == "union") {
            int u, v;
            cin >> u >> v;
            u--, v--;
            cnts.top() += dsu.unite(u, v);
            cout << dsu.comp << '\n';
        }
        if (t == "persist") {
            cnts.push(0);
        }
        if (t == "rollback") {
            while (cnts.top()--)
                dsu.rollback();
            cnts.pop();
            cout << dsu.comp << '\n';
        }
        trace(dsu.states);
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
    }
}
