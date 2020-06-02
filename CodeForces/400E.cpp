/* Author - Neel Aryan (@neelaryan2) */
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
const int B = 17;
struct Node {
    int pre, suf, len;
    ll ans;
    Node(int t = 0) {
        pre = suf = ans = t;
        len = 1;
    }
    string rep() {
        string s(len, '0');
        for (int i = 0; i < pre; i++)
            s[i] = '1';
        for (int i = 0; i < suf; i++)
            s[len - 1 - i] = '1';
        return s;
    }
};
struct segtree {
    vector<Node> t;
    int n;
    segtree() {}
    Node combine(Node a, Node b) {
        Node r = Node();
        r.ans = a.ans + b.ans;
        r.len = a.len + b.len;
        r.ans += 1LL * a.suf * b.pre;
        r.pre = a.pre, r.suf = b.suf;
        if (a.pre == a.len) r.pre += b.pre;
        if (b.pre == b.len) r.suf += a.suf;
        return r;
    }
    void build(int m) {
        n = m;
        t.resize(2 * n);
        for (int i = 0; i < n; i++)
            t[i + n] = Node();
        for (int i = n - 1; i > 0; i--)
            t[i] = combine(t[i << 1], t[i << 1 | 1]);
    }
    void update(int p, int x) {  // on 0-indexed p
        for (t[p += n] = Node(x); p >>= 1;)
            t[p] = combine(t[p << 1], t[p << 1 | 1]);
    }
    Node query(int l, int r) {  // interval [l,r]
        Node resl, resr;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
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
    int n, m;
    cin >> n >> m;
    segtree tree[B];
    for (int i = 0; i < B; i++)
        tree[i].build(n);
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        for (int j = 0; j < B; j++)
            if ((e >> j) & 1)
                tree[j].update(i, 1);
    }
    for (int i = 0; i < m; i++) {
        int p, x;
        cin >> p >> x;
        ll ans = 0;
        for (int j = 0; j < B; j++) {
            tree[j].update(p - 1, (x >> j) & 1);
            Node cur = tree[j].query(0, n - 1);
            ans += cur.ans * (1LL << j);
        }
        cout << ans << '\n';
    }
}
