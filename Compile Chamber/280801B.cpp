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
const static int NO_OP = 0;

struct seg_tree_lazy_ap {
    vector<ll> t, d, ap;
    int n, h;
    seg_tree_lazy_ap() {}
    void init(int m = 0) {
        n = m;
        h = 32 - __builtin_clz(n);
        d.assign(n, 0);
        ap.assign(n, 0);
        t.assign(2 * n, 0);
    }
    void build(vector<int> a) {
        init(a.size());
        for (int i = 0; i < n; i++)
            t[i + n] = a[i];
        push_up(0, n - 1);
    }
    // c is the size of segment
    void calc(int p, ll c) {
        // pull from children
        t[p] = t[p << 1] + t[p << 1 | 1] + d[p] * c + ap[p] * ((c * (c - 1)) / 2);
    }
    void apply(int p, ll v1, ll v2, ll c) {
        // apply to children
        if (p < n) {
            d[p] += v1;
            ap[p] += v2;
        }
        t[p] += v1 * c + v2 * ((c * (c - 1)) / 2);
    }
    void push_up(int l, int r = -1) {
        if (r == -1) r = l;
        l += n, r += n;
        for (int k = 2; l > 1; k <<= 1) {
            l >>= 1, r >>= 1;
            for (int i = r; i >= l; --i)
                calc(i, k);
        }
    }
    void push_down(int l, int r = -1) {
        if (r == -1) r = l;
        int s = h, k = 1 << (h - 1);
        for (l += n, r += n; s > 0; --s, k >>= 1) {
            for (int i = l >> s; i <= r >> s; ++i) {
                apply(i << 1, d[i], ap[i], k);
                apply(i << 1 | 1, d[i] + k * ap[i], ap[i], k);
                d[i] = 0, ap[i] = 0;
            }
        }
    }
    void add(int l, int r, ll a, ll d) {
        if (r < l || r >= n || l < 0) return;
        int _l = l, _r = r;
        l += n, r += n + 1;
        push_down(_l), push_down(_r);
        ll lef_a = a, righ_a = a + (r - l) * d;
        for (ll c = 1; l < r; l >>= 1, r >>= 1, c <<= 1) {
            if (l & 1) {
                apply(l++, lef_a, d, c);
                lef_a += c * d;
            }
            if (r & 1) {
                righ_a -= c * d;
                apply(--r, righ_a, d, c);
            }
        }
        push_up(_l), push_up(_r);
    }
    ll query(int l, int r) {
        ll res = 0;
        if (r < l || r >= n || l < 0)
            return res;
        push_down(l), push_down(r);
        l += n, r += n + 1;
        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res += t[l++];
            if (r & 1) res += t[--r];
        }
        return res;
    }
};

void print(seg_tree_lazy_ap& tree) {
    return;
    int n = tree.n;
    for (int i = 1; i < 2 * n; i++) {
        if (i < n) {
            cerr << "(" << tree.t[i] << ",";
            cerr << tree.d[i] << ",";
            cerr << tree.ap[i] << ")";
        } else
            cerr << "(" << tree.t[i] << ",leaf)";

        if ((i & (i + 1)) == 0)
            cerr << endl;
        else
            cerr << ",";
    }
    cerr << endl;
}

void solve(int test) {
    int n, m;
    cin >> n >> m;
    seg_tree_lazy_ap aptree;
    aptree.build(vector<int>(n, 0));
    print(aptree);
    while (m--) {
        ll t, l, r, a, d;
        cin >> t;
        if (t == 1) {
            cin >> l >> r >> a >> d;
            l--, r--;
            aptree.add(l, r, a, d);
        }
        if (t == 2) {
            cin >> l;
            l--;
            r = aptree.query(l, l);
            cout << r << '\n';
        }
        print(aptree);
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
