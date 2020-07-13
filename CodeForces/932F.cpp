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
// clang-format off
struct Line {
    mutable ll k, m, p;
    bool operator<(const Line& o) const { return k < o.k; }
    bool operator<(ll x) const { return p < x; }
};
struct ConvexHull : multiset<Line, less<>> {
    // (for doubles, use inf = 1/.0, div(a,b) = a/b)
    const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
    void add(ll k, ll m) {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    ll query(ll x) {
        assert(!empty());
        auto l = *lower_bound(x);
        return l.k * x + l.m;
    }
};
// clang-format on
vector<int> a, b, siz;
vector<ll> dp;
vector<vi> adj;
vector<ConvexHull> hulls;
void dfs(int v, int p = -1) {
    int big = -1, bigchild = -1;
    for (int u : adj[v]) {
        if (u == p) continue;
        dfs(u, v);
        siz[v] += siz[u];
        if (siz[u] > big) {
            big = siz[u];
            bigchild = u;
        }
    }
    if (bigchild == -1) {
        dp[v] = 0;
        hulls[v].add(-b[v], 0);
        return;
    }
    for (int u : adj[v]) {
        if (u == p || u == bigchild) continue;
        for (auto& line : hulls[u])
            hulls[bigchild].add(line.k, line.m);
    }
    swap(hulls[bigchild], hulls[v]);
    dp[v] = -hulls[v].query(a[v]);
    hulls[v].add(-b[v], -dp[v]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    adj.resize(n);
    a.resize(n);
    b.resize(n);
    dp.resize(n);
    hulls.resize(n);
    siz.assign(n, 1);
    for (int& e : a) cin >> e;
    for (int& e : b) cin >> e;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[v].eb(u);
        adj[u].eb(v);
    }
    dfs(0);
    for (ll& i : dp)
        cout << i << ' ';
    cout << '\n';
}
