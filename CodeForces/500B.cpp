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
int root(int a) {
    if (par[a] == -1) par[a] = a;
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
}
void solve(int test) {
    int n;
    cin >> n;
    vector<int> p(n);
    siz.assign(n, 1);
    par.assign(n, -1);
    for (int& e : p) cin >> e;
    vector<string> adj(n);
    for (int i = 0; i < n; i++) {
        cin >> adj[i];
        for (int j = 0; j < n; j++) {
            if (adj[i][j] == '1') {
                add(i, j);
            }
        }
    }
    vector<vi> vec(n);
    for (int i = 0; i < n; i++)
        vec[root(i)].eb(p[i]);
    for (int i = 0; i < n; i++) {
        if (root(i) != i) continue;
        sort(all(vec[i]));
    }
    for (int i = n - 1; i >= 0; i--) {
        int j = root(i);
        p[i] = vec[j].back();
        vec[j].pop_back();
    }
    for (int i : p) cout << i << ' ';
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
        cout << "\n";
    }
}
