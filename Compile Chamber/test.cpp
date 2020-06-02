
struct segtree {
    vector<ll> t, d;
    int n, h;
    ll init = 2e18;
    segtree(int m) {
        n = m;
        h = 32 - __builtin_clz(n);
        d.assign(n, 0);
        t.assign(2 * n, init);
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
        build(_l), build(_r);
    }
    ll query(int l, int r) {
        l += n, r += n + 1;
        push(l), push(r);
        ll resl = init, resr = init;
        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) resl = combine(resl, t[l++]);
            if (r & 1) resr = combine(t[--r], resr);
        }
        return combine(resl, resr);
    }
};


struct segtree {
    vector<int> t;
    int n;
    segtree() {}
    int combine(int a, int b) {
        return max(a, b);
    }
    void build(vector<int>& a) {
        n = a.size();
        t.resize(2 * n);
        for (int i = 0; i < n; i++)
            t[i + n] = a[i];
        for (int i = n - 1; i > 0; i--)
            t[i] = combine(t[i << 1], t[i << 1 | 1]);
    }
    void update(int p, int x) {  // on 0-indexed p
        for (t[p += n] = x; p >>= 1;)
            t[p] = combine(t[p << 1], t[p << 1 | 1]);
    }
    int query(int l, int r) {  // interval [l,r]
        int resl = 0, resr = 0;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) resl = combine(resl, t[l++]);
            if (r & 1) resr = combine(t[--r], resr);
        }
        return combine(resl, resr);
    }
};
