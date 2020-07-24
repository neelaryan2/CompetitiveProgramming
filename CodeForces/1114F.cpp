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
const int N = 300;
const int kMod = 1e9 + 7;
struct ModInt {
    long long n;
    ModInt(long long n = 0) : n(n % kMod) {}
    ModInt operator+(const ModInt& oth) { return n + oth.n; }
    ModInt operator-(const ModInt& oth) { return n - oth.n; }
    ModInt operator*(const ModInt& oth) { return n * oth.n; }
    long long get() { return n < 0 ? n + kMod : n; }
};
ModInt lgpow(ModInt b, int e = -1) {
    if (b.get() == 0) return 0;
    ModInt r;
    e = e % (kMod - 1);
    if (e < 0) e += kMod - 1;
    for (r = 1; e; e >>= 1, b = b * b)
        if (e & 1) r = r * b;
    return r;
}
vector<ll> mask(N + 1, 0);
struct my_node {
    ModInt val;
    ll or_val;
    my_node(int x = 1) {
        val = x;
        or_val = mask[x];
    }
    my_node operator+(const my_node& oth) {
        my_node r;
        r.or_val = or_val | oth.or_val;
        r.val = val * oth.val;
        return r;
    }
    my_node operator*(const int& x) {
        my_node r = *this;
        r.val = lgpow(r.val, x);
        return r;
    }
};
template <class node>
struct seg_tree_lazy {
    vector<node> t, d;
    int n, h;
    seg_tree_lazy() {}
    void init(int m = 0) {
        n = m;
        h = 32 - __builtin_clz(n);
        d.resize(n);
        t.resize(2 * n);
    }
    void apply(int p, node value, int c) {
        if (p < n) d[p] = d[p] + value;
        t[p] = t[p] + value * c;
    }
    void push_up(int p) {
        for (int c = 2; p >>= 1; c <<= 1)
            t[p] = t[p << 1] + t[p << 1 | 1] + d[p] * c;
    }
    void push_down(int p) {
        for (int s = h; s > 0; --s) {
            int i = p >> s;
            if (d[i].or_val != 0) {
                int c = 1 << (s - 1);
                apply(i << 1, d[i], c);
                apply(i << 1 | 1, d[i], c);
                d[i].val = 1;
                d[i].or_val = 0;
            }
        }
    }
    void add(int l, int r, int v) {
        if (r < l || r >= n || l < 0) return;
        l += n, r += n + 1;
        int _l = l, _r = r;
        node value(v);
        for (int c = 1; l < r; l >>= 1, r >>= 1, c <<= 1) {
            if (l & 1) apply(l++, value, c);
            if (r & 1) apply(--r, value, c);
        }
        push_up(_l), push_up(_r - 1);
    }
    node query(int l, int r) {
        node res;
        if (r < l || r >= n || l < 0) return res;
        l += n, r += n + 1;
        push_down(l), push_down(r - 1);
        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = res + t[l++];
            if (r & 1) res = res + t[--r];
        }
        return res;
    }
};
int least[N + 1];
vector<int> p;
void sieve() {
    least[0] = 0;
    least[1] = 1;
    for (int i = 2; i <= N; i++)
        least[i] = (i % 2) ? i : 2;
    for (int i = 3; i * i <= N; i += 2) {
        if (least[i] != i) continue;
        for (int j = i * i; j <= N; j += i)
            if (least[j] == j)
                least[j] = i;
    }
    for (int i = 2; i <= N; i++)
        if (least[i] == i) p.eb(i);
    for (int i = 2; i <= N; i++) {
        ll& cur = mask[i];
        for (int j = 0; j < p.size(); j++) {
            if (i % p[j]) continue;
            cur ^= (1LL << j);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve();
    vector<ModInt> inv(p.size());
    for (int i = 0; i < p.size(); i++)
        inv[i] = lgpow(p[i]);
    int n, q;
    cin >> n >> q;
    seg_tree_lazy<my_node> stree;
    stree.init(n);
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        stree.add(i, i, e);
    }
    while (q--) {
        int l, r, x;
        string s;
        cin >> s >> l >> r;
        l--, r--;
        if (s == "MULTIPLY") {
            cin >> x;
            stree.add(l, r, x);
        }
        if (s == "TOTIENT") {
            my_node ret = stree.query(l, r);
            ModInt ans = ret.val;
            for (int i = 0; i < p.size(); i++)
                if ((ret.or_val >> i) & 1)
                    ans = (ans * (p[i] - 1)) * inv[i];
            cout << ans.get() << '\n';
        }
    }
}
