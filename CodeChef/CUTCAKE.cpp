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

struct pt {
    ll x, y;
    pt() {}
    pt(ll _x, ll _y) : x(_x), y(_y) {}
    pt operator-(const pt& p) const {
        return pt(x - p.x, y - p.y);
    }
    ll cross(const pt& p) const {
        return x * p.y - y * p.x;
    }
    ll cross(const pt& a, const pt& b) const {
        return (a - *this).cross(b - *this);
    }
    ll dot(const pt& p) const {
        return x * p.x + y * p.y;
    }
    ll dot(const pt& a, const pt& b) const {
        return (a - *this).dot(b - *this);
    }
    ll sqrLength() const {
        return this->dot(*this);
    }
    bool operator==(const pt& p) const {
        return x == p.x && y == p.y;
    }
    bool operator<(const pt& p) const {
        if (x != p.x) return x < p.x;
        return y < p.y;
    }
};
bool ccw(pt a, pt b, pt c) {
    return ((b - a).cross(c - b)) > 0;
}
bool convex(pt a, pt b, pt c, pt d) {
    return ((ccw(a, b, c) && ccw(b, c, d) && ccw(c, d, a) && ccw(d, a, b)) ||
            (ccw(a, d, c) && ccw(d, c, b) && ccw(c, b, a) && ccw(b, a, d)));
}
int sgn(const ll& a) { return a >= 0 ? (a ? 1 : 0) : -1; }

template <class T>
T det3(T a1, T a2, T a3, T b1, T b2, T b3, T c1, T c2, T c3) {
    return a1 * (b2 * c3 - c2 * b3) - a2 * (b1 * c3 - c1 * b3) +
           a3 * (b1 * c2 - c1 * b2);
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define shuf(v) shuffle((v).begin(), (v).end(), rng);

const ll inf = 1e18 + 1;
const pt inf_pt = pt(inf, inf);

vector<pt> points;
vector<int> A, B, parent;
vector<vi> delaunay;
vector<pii> flips, removes;

int gen(int lo = 0, int hi = 256) {
    vi v = {0, 64, 256};
    int cur = abs((ll)rng()) % 3;
    return v[cur];
    // int cur = abs((ll)rng()) % (hi - lo + 1);
    // return cur + lo;
}
int gp(int u) { return (u == parent[u] ? u : parent[u] = gp(parent[u])); }
pii makeEdge(int u, int v) {
    return {min(u, v), max(u, v)};
}
bool replaceDiagonal(map<pii, set<int>>& mp, int u, int v, int x, int y) {
    auto e = makeEdge(u, v);
    if (!mp[e].count(x)) return false;
    mp[e].erase(x);
    mp[e].insert(y);
    return (mp[e].size() <= 2);
}
int flipDiagonal(map<pii, set<int>>& mp, pii diag) {
    auto it = mp.find(diag);
    if (it == mp.end()) return 0;
    int x = diag.fi;
    int y = diag.se;
    if ((it->se).size() != 2) return 0;
    int s = *(it->se).begin();
    int t = *(it->se).rbegin();
    if (!convex(points[s], points[x], points[t], points[y])) return 0;
    mp.erase(diag);
    mp[makeEdge(s, t)] = {x, y};
    if (!replaceDiagonal(mp, x, s, y, t)) return -1;
    if (!replaceDiagonal(mp, s, y, x, t)) return -1;
    if (!replaceDiagonal(mp, y, t, x, s)) return -1;
    if (!replaceDiagonal(mp, t, x, y, s)) return -1;
    return 1;
}
bool solve(map<pii, set<int>> mp) {
    int F = gen();
    int n = points.size();
    int m = delaunay.size();
    int r = B.size();
    vector<pii> diagonals;
    for (auto p : mp)
        if (p.se.size() == 2)
            diagonals.eb(p.fi);

    shuf(diagonals);
    flips.clear();
    int flips_cnt = 0;
    for (int i = 0; i < diagonals.size(); i++) {
        if (flips_cnt == F) break;
        int c = flipDiagonal(mp, diagonals[i]);
        if (c < 0) return false;
        if (c > 0) {
            flips_cnt++;
            flips.eb(diagonals[i]);
        }
    }

    diagonals.clear();
    vector<vector<int>> striangles;
    for (auto p : mp) {
        if (p.se.size() == 2)
            diagonals.eb(p.fi);
        int x = p.fi.fi;
        int y = p.fi.se;
        for (int z : p.se) {
            vector<int> tri = {x, y, z};
            sort(all(tri));
            striangles.eb(tri);
        }
    }
    sort(all(striangles));
    int nt = unique(all(striangles)) - striangles.begin();
    striangles.resize(nt);
    parent.resize(nt);
    iota(all(parent), 0);

    shuf(diagonals);

    removes.clear();
    for (int it = 0; it < m - r; it++) {
        int i = diagonals[it].fi;
        int j = diagonals[it].se;
        int k = *mp[diagonals[it]].begin();
        int l = *mp[diagonals[it]].rbegin();
        vector<int> t1 = {i, j, k};
        sort(all(t1));
        vector<int> t2 = {i, j, l};
        sort(all(t2));
        int u = lb(all(striangles), t1) - striangles.begin();
        int v = lb(all(striangles), t2) - striangles.begin();
        if (gp(u) == gp(v))
            return false;
        parent[gp(u)] = gp(v);
        removes.eb(diagonals[it]);
    }

    map<int, int> areas;
    for (int i = 0; i < nt; i++) {
        int pi = gp(i);
        int x = striangles[i][0];
        int y = striangles[i][1];
        int z = striangles[i][2];
        ll area = (points[y] - points[x]).cross(points[z] - points[x]);
        if (area < 0) area = -area;
        areas[pi] += area;
    }
    A.clear();
    for (auto p : areas)
        A.eb(p.se);
    sort(all(A));
    return (A.size() == r) && (removes.size() == m - r);
}

int main() {
    int n, m, r;
    cin >> n >> m >> r;

    points.resize(n);
    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;

    delaunay.resize(m);
    map<pii, set<int>> mp;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--, c--;
        delaunay[i] = {a, b, c};
        mp[makeEdge(a, b)].insert(c);
        mp[makeEdge(b, c)].insert(a);
        mp[makeEdge(c, a)].insert(b);
    }

    B.resize(r);
    for (int i = 0; i < r; i++)
        cin >> B[i];
    sort(all(B));

    int tries = 700;
    vector<pii> final_flips, final_removes;
    ll ans = inf;
    while (tries-- || ans == inf) {
        bool b = solve(mp);
        if (!b) continue;
        ll cur = 0;
        for (int i = 0; i < r; i++)
            cur += abs(A[i] - B[i]);
        if (cur < ans) {
            swap(ans, cur);
            swap(final_flips, flips);
            swap(final_removes, removes);
        }
    }
    cout << final_flips.size() << '\n';
    for (pii p : final_flips)
        cout << (p.fi + 1) << ' ' << (p.se + 1) << '\n';
    for (pii p : final_removes)
        cout << (p.fi + 1) << ' ' << (p.se + 1) << '\n';
    cerr << ans << '\n';
    return 0;
}
