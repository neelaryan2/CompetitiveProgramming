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
const int K = 40;
struct node {
    int cnt[K], pref[K + 1];
    ll inv;
    node(int x = -1) {
        pref[0] = 0, inv = 0;
        for (int i = 0; i < K; i++) {
            cnt[i] = (i == x);
            pref[i + 1] = pref[i] + cnt[i];
        }
    }
    node operator+(const node& oth) {
        node r;
        for (int i = 0; i < K; i++) {
            r.inv += 1LL * cnt[i] * oth.pref[i];
            r.cnt[i] = cnt[i] + oth.cnt[i];
            r.pref[i + 1] = r.pref[i] + r.cnt[i];
        }
        r.inv += inv + oth.inv;
        return r;
    }
};
template <class node>
struct seg_tree {
    vector<node> t;
    int n;
    seg_tree() {}
    void build(vector<int>& a) {
        n = a.size();
        t.resize(2 * n);
        for (int i = 0; i < n; i++)
            t[i + n] = node(a[i]);
        for (int i = n - 1; i > 0; i--)
            t[i] = t[i << 1] + t[i << 1 | 1];
    }
    void update(int p, int x) {  // on 0-indexed p
        for (t[p += n] = node(x); p >>= 1;)
            t[p] = t[p << 1] + t[p << 1 | 1];
    }
    node query(int l, int r) {  // interval [l,r]
        node resl, resr;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) resl = resl + t[l++];
            if (r & 1) resr = t[--r] + resr;
        }
        return resl + resr;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int& e : a) cin >> e, e--;
    seg_tree<node> stree;
    stree.build(a);
    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;
        l--, r--;
        if (t == 1) {
            node res = stree.query(l, r);
            cout << res.inv << '\n';
        }
        if (t == 2) {
            stree.update(l, r);
        }
    }
}
