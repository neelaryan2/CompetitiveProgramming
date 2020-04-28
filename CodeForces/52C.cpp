#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
const ll inf = 2e18;
struct segtree {
    vector<ll> t, d;
    int n, h;
    segtree(int m) {
        n = m;
        h = 32 - __builtin_clz(n);
        d.assign(n, 0);
        t.assign(2 * n, 0);
    }
    ll combine(ll a, ll b) {
        return min(a, b);
    }
    void apply(int p, ll value) {
        t[p] += value;
        if (p < n) d[p] += value;
    }
    void build(int p) {
        while (p > 1)
            p >>= 1, t[p] = combine(t[p << 1], t[p << 1 | 1]) + d[p];
    }
    void push(int p) {
        for (int s = h; s > 0; --s) {
            int i = p >> s;
            if (d[i] != 0) {
                apply(i << 1, d[i]);
                apply(i << 1 | 1, d[i]);
                d[i] = 0;
            }
        }
    }
    void inc(int l, int r, ll value) {
        l += n, r += n + 1;
        int _l = l, _r = r;
        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) apply(l++, value);
            if (r & 1) apply(--r, value);
        }
        build(_l), build(_r - 1);
    }
    ll query(int l, int r) {
        l += n, r += n + 1;
        push(l), push(r - 1);
        ll resl = inf, resr = inf;
        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) resl = combine(resl, t[l++]);
            if (r & 1) resr = combine(t[--r], resr);
        }
        return combine(resl, resr);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, l, r, v;
    cin >> n;
    segtree tree = segtree(n);
    for (int i = 0; i < n; i++) {
        ll e;
        cin >> e;
        tree.inc(i, i, e);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> l >> r;
        if (cin.get() == 10) {
            ll mn = inf;
            if (l <= r)
                mn = tree.query(l, r);
            else
                mn = min(tree.query(0, r), tree.query(l, n - 1));
            cout << mn << '\n';
        } else {
            cin >> v;
            if (l <= r)
                tree.inc(l, r, v);
            else
                tree.inc(0, r, v), tree.inc(l, n - 1, v);
        }
    }
}