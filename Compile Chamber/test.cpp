#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int n, d;
ll ans = 0;
vector<int> par, p, siz;
vector<pii> edges;
vector<vector<int>> vecs;
ll merge(vector<int>& a, vector<int>& b) {
    ll ret = 0;
    for (int e : a) {
        int id1 = lower_bound(b.begin(), b.end(), e - d) - b.begin();
        int id2 = upper_bound(b.begin(), b.end(), e + d) - b.begin();
        ret += id2 - id1;
    }
    vector<int> tmp(a.size() + b.size());
    int id = 0, i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j])
            tmp[id++] = a[i++];
        else
            tmp[id++] = b[j++];
    }
    while (i < a.size()) tmp[id++] = a[i++];
    while (j < b.size()) tmp[id++] = b[j++];
    a.resize(tmp.size());
    for (i = 0; i < tmp.size(); i++)
        a[i] = tmp[i];
    b.clear();
    return ret;
}
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
    if (siz[a] > siz[b]) swap(a, b);
    par[b] = a;
    siz[a] += siz[b];
    ans += merge(vecs[a], vecs[b]);
}
void init() {
    edges.resize(n - 1);
    p.resize(n - 1);
    par.assign(n, -1);
    siz.assign(n, 1);
    vecs.resize(n, vector<int>(1));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> d;
    init();
    for (int i = 0; i < n; i++)
        cin >> vecs[i][0];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges[i] = {u, v};
    }
    for (int& e : p) cin >> e, e--;
    reverse(p.begin(), p.end());
    vector<ll> fin(n - 1, 0);
    for (int i = 0; i < n - 1; i++) {
        pii e = edges[p[i]];
        fin[i] = ans;
        add(e.first, e.second);
    }
    reverse(fin.begin(), fin.end());
    for (ll& e : fin) cout << e << '\n';
}