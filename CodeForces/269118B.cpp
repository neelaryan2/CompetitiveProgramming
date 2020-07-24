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
struct suffix_array {
    int n, alphabet = 256;
    string s;
    vector<int> p, c, cnt, base_lcp, logs;
    vector<vector<int>> st;
    void build_suffix_array() {
        // base case k = 0
        // count sort
        for (int i = 0; i < n; i++)
            cnt[s[i]]++;
        for (int i = 1; i < alphabet; i++)
            cnt[i] += cnt[i - 1];
        for (int i = 0; i < n; i++)
            p[--cnt[s[i]]] = i;
        // calculate equivalence classes
        c[p[0]] = 0;
        int classes = 1;
        for (int i = 1; i < n; i++) {
            if (s[p[i]] != s[p[i - 1]])
                classes++;
            c[p[i]] = classes - 1;
        }
        // transition k -> k + 1
        vector<int> pn(n), cn(n);
        for (int h = 0, dh = 1; (1 << h) < n; ++h, dh <<= 1) {
            // back shift
            for (int i = 0; i < n; i++) {
                pn[i] = p[i] - dh;
                if (pn[i] < 0) pn[i] += n;
            }
            // count sort
            fill(cnt.begin(), cnt.begin() + classes, 0);
            for (int i = 0; i < n; i++)
                cnt[c[pn[i]]]++;
            for (int i = 1; i < classes; i++)
                cnt[i] += cnt[i - 1];
            for (int i = n - 1; i >= 0; i--)
                p[--cnt[c[pn[i]]]] = pn[i];
            // recalculate equivalence classes
            cn[p[0]] = 0, classes = 1;
            pair<int, int> prv = {c[p[0]], c[(p[0] + dh) % n]};
            for (int i = 1; i < n; i++) {
                pair<int, int> cur = {c[p[i]], c[(p[i] + dh) % n]};
                if (cur != prv)
                    ++classes;
                cn[p[i]] = classes - 1;
                prv = cur;
            }
            c.swap(cn);
        }
    }
    void build_lcp() {
        int k = 0;
        // base_lcp[0] is useless
        base_lcp.assign(n, n);
        for (int i = 0; i < n - 1; i++) {
            int j = p[c[i] - 1];
            while (s[i + k] == s[j + k]) k++;
            base_lcp[c[i]] = k;
            k = max(k - 1, 0);
        }
    }
    void build_sparse_table() {
        // precalcuation logs[i] = int(log2(i))
        logs.assign(n + 1, 0);
        for (int i = 2; i <= n; i++)
            logs[i] = logs[i / 2] + 1;
        // sparse table building
        st.assign(n, vector<int>(logs[n] + 1));
        for (int i = 0; i < n; i++)
            st[i][0] = base_lcp[i];
        for (int j = 1; j <= logs[n]; j++)
            for (int i = 0; i + (1 << j) <= n; i++)
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
    int lcp(int i, int j) {
        // lcp of i-th suffix and j-th suffix, 0-indexed
        // i, j are original indices, not in p!
        if (i == j) return n - i - 1;
        int L = c[i], R = c[j];
        if (R < L) swap(R, L);
        int len = logs[R - L];
        int mn = min(st[L + 1][len], st[R - (1 << len) + 1][len]);
        return mn;
    }
    suffix_array(const string& ss) {
        s = ss + "$";
        n = s.size();
        p.resize(n);
        c.resize(n);
        cnt.assign(max(n, alphabet), 0);
        build_suffix_array();
        // build_lcp();
        // build_sparse_table();
    }
    int lower_bound(const string& t) {
        int k = t.size();
        int lo = 0, hi = n, mid;
        while (lo < hi - 1) {
            mid = lo + (hi - lo) / 2;
            if (s.substr(p[mid], k) < t)
                lo = mid;
            else
                hi = mid;
        }
        return hi;
    }
    int upper_bound(const string& t) {
        int k = t.size();
        int lo = 0, hi = n, mid;
        while (lo < hi - 1) {
            mid = lo + (hi - lo) / 2;
            if (s.substr(p[mid], k) <= t)
                lo = mid;
            else
                hi = mid;
        }
        return hi;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string _;
    cin >> _;
    suffix_array s(_);
    int q;
    cin >> q;
    while (q--) {
        string t;
        cin >> t;
        int ans = s.ub(t) - s.lb(t);
        cout << ans << '\n';
    }
}
