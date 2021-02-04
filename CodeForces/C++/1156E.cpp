/* Author - Neel Aryan (@neelaryan2) */
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
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
vector<int> p, pos;
segtree tree;
ll solve(int s, int e) {
    if (s >= e) return 0;
    int m = pos[tree.query(s, e)];
    trace(s, m, e);
    ll ans = solve(s, m - 1) + solve(m + 1, e);
    if (m - s < e - m) {
        for (int i = s; i < m; i++) {
            int cur = p[m] - p[i] - 1;
            if (cur >= pos.size()) continue;
            if (m < pos[cur] && pos[cur] <= e)
                ans++;
        }
    } else {
        for (int i = e; i > m; i--) {
            int cur = p[m] - p[i] - 1;
            if (cur >= pos.size()) continue;
            if (s <= pos[cur] && pos[cur] < m)
                ans++;
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    p.resize(n);
    pos.resize(n);
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e, e--;
        p[i] = e;
        pos[e] = i;
    }
    tree.build(p);
    cout << solve(0, n - 1) << '\n';
}
