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

struct segtree {
    vector<int> t;
    int n;
    segtree() {}
    void build(vector<int>& a) {
        n = a.size();
        t.resize(2 * n);
        for (int i = 0; i < n; i++)
            t[i + n] = a[i];
        for (int i = n - 1; i > 0; i--)
            t[i] = min(t[i << 1], t[i << 1 | 1]);
    }
    void update(int p, int x) {  // on 0-indexed p
        for (t[p += n] = x; p >>= 1;)
            t[p] = min(t[p << 1], t[p << 1 | 1]);
    }
    int query(int l, int r) {  // interval [l,r]
        int resl = 1e9, resr = 1e9;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) resl = min(resl, t[l++]);
            if (r & 1) resr = min(t[--r], resr);
        }
        return min(resl, resr);
    }
};
const int N = 1e6 + 3;
vector<int> cnt[2 * N + 10];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> p(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        char c = s[i - 1];
        p[i] = p[i - 1];
        if (c == '(') p[i]++;
        if (c == ')') p[i]--;
    }
    segtree tree;
    tree.build(p);
    cnt[N].pb(0);
    trace(p);
    vector<int> lcnt(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int csum = p[i] + N;
        int k = cnt[csum].size();
        int lo = -1, hi = k, mid;
        while (lo < hi - 1) {
            mid = (lo + hi) / 2;
            int cur = tree.query(cnt[csum][mid] + 1, i);
            if (cur >= p[i])
                hi = mid;
            else
                lo = mid;
        }
        trace(i, cnt[csum], csum - N, k, hi);
        if (hi != k) lcnt[i - cnt[csum][hi]]++;
        cnt[csum].pb(i);
    }
    for (int i = n; i >= 0; i--) {
        if (lcnt[i] != 0) {
            cout << i << ' ' << lcnt[i] << '\n';
            return 0;
        }
    }
    cout << 0 << ' ' << 1 << '\n';
}
