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
struct node {
    vector<int> v;
    node() {}
    node(int x) { v.eb(x); trace(v); }
    node operator+(const node& oth) {
        node r;
        for(int i : v) r.v.eb(i);
        for(int i : oth.v) r.v.eb(i);
        // merge(all(v), all(oth.v), r.v.begin());
        sort(all(r.v));
        trace(v, oth.v, r.v);
        return r;
    }
    int query(int x) {
        int j = ub(all(v), x) - v.begin();
        return v.size() - j;
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
    int query(int l, int r) {  // interval [l,r]
        int res = 0, x = r;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res += t[l++].query(x);
            if (r & 1) res += t[--r].query(x);
        }
        return res;
    }
};
void solve(int test) {
    seg_tree<node> st;
    int n, q;
    cin >> n >> q;
    vector<int> a(n), nxt(n, 1e9);
    map<int, int> ahead;
    for (int& e : a) cin >> e;
    for (int i = n - 1; i >= 0; i--) {
        auto it = ahead.find(a[i]);
        if (it != ahead.end())
            nxt[i] = it->se;
        ahead[a[i]] = i;
    }
    st.build(nxt);
    trace(nxt);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int res = st.query(l, r);
        cout << res << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
