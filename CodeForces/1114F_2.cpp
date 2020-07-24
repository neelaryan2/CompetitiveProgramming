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
        my_node r = *this;
        r.val = val * oth.val;
        r.or_val = or_val | oth.or_val;
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
    vector<node> t, lazy;
    int n;
    void init(int m) {
        n = m;
        t.resize(4 * n);
        lazy.resize(4 * n);
    }
    void push(int v, int l, int r) {
        lazy[v * 2] = lazy[v * 2] + lazy[v];
        lazy[v * 2 + 1] = lazy[v * 2 + 1] + lazy[v];
        t[v * 2] = t[v * 2] + lazy[v] * l;
        t[v * 2 + 1] = t[v * 2 + 1] + lazy[v] * r;
        lazy[v] = node();
    }
    void add_aux(int v, int tl, int tr, int l, int r, int addend) {
        if (l > r) return;
        if (l == tl && tr == r) {
            t[v] = t[v] + node(addend) * (tr - tl + 1);
            lazy[v] = lazy[v] + addend;
        } else {
            int tm = (tl + tr) / 2;
            push(v, tm - tl + 1, tr - tm);
            add_aux(v * 2, tl, tm, l, min(r, tm), addend);
            add_aux(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, addend);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }
    node query_aux(int v, int tl, int tr, int l, int r) {
        if (l > r) return node();
        if (l == tl && tr == r) return t[v];
        int tm = (tl + tr) / 2;
        push(v, tm - tl + 1, tr - tm);
        return query_aux(v * 2, tl, tm, l, min(r, tm)) +
               query_aux(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }
    void add(int l, int r, int x) {
        return add_aux(1, 0, n - 1, l, r, x);
    }
    node query(int l, int r) {
        return query_aux(1, 0, n - 1, l, r);
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
            trace(ans.get());
            for (int i = 0; i < p.size(); i++)
                if ((ret.or_val >> i) & 1)
                    ans = (ans * (p[i] - 1)) * inv[i];
            cout << ans.get() << '\n';
        }
    }
}
