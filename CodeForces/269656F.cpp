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

struct suf_array {
    int n, alphabet = 256;
    string s;
    bool store_cc;
    vector<int> p, c, cnt, base_lcp, logs;
    vector<vector<int>> st, cc;
    suf_array() {}
    void build_suf_array() {
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
        if (store_cc)
            cc.push_back(c);
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
            if (store_cc)
                cc.push_back(cn);
            c.swap(cn);
        }
    }
    void build_lcp() {
        int k = 0;
        // base_lcp[0] is useless
        base_lcp.assign(n, 0);
        for (int i = 0; i < n - 1; i++) {
            int j = p[c[i] - 1];
            while (i + k < n &&
                   j + k < n &&
                   s[i + k] == s[j + k])
                k++;
            base_lcp[c[i]] = k;
            k = max(k - 1, 0);
        }
    }
    void build_logs() {
        // precalculation logs[i] = int(log2(i))
        logs.assign(n + 1, 0);
        for (int i = 2; i <= n; i++)
            logs[i] = logs[i / 2] + 1;
    }
    void build_sparse_table() {
        // sparse table building
        st.assign(n, vector<int>(logs[n] + 1));
        for (int i = 0; i < n; i++)
            st[i][0] = base_lcp[i];
        for (int j = 1; j <= logs[n]; j++)
            for (int i = 0; i + (1 << j) <= n; i++)
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
    void build(const string& ss, char sentinel = char(36)) {
        s = ss + sentinel;
        n = s.size();
        p.resize(n);
        c.resize(n);
        cnt.assign(max(n, alphabet), 0);
        store_cc = false;
        build_suf_array();
        build_lcp();
        // build_logs();
        // build_sparse_table();
    }
    pair<int, int> repr(int i, int l) {
        // returns pair representation of prefix
        // of length l if i-th suffix
        assert(store_cc);
        int k = logs[l];
        return make_pair(cc[k][i], cc[k][(i + l - (1 << k)) % n]);
    }
    int lcp(int i, int j) {
        // lcp of i-th suffix and j-th suffix, 0-indexed
        // i, j are original indices, not in p!
        if (i == j) return n - i - 1;
        int L = c[i], R = c[j];
        if (R < L) swap(R, L);
        int len = logs[R - L];
        L++, R++;
        int mn = min(st[L][len], st[R - (1 << len)][len]);
        return mn;
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
    void print(int w = 5) {
        for (int i = 1; i < n; i++) {
            cerr << left << setw(w) << p[i]
                 << setw(w) << base_lcp[i]
                 << s.substr(p[i], n - p[i] - 1) << '\n';
        }
    }
};
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define shuf(v) shuffle((v).begin(), (v).end(), rng);
string base = "abcdefghijklmnopqrstuvwxyz";
string gen_random(int len) {
    int k = base.size();
    string st(len, 'a');
    for (char& c : st)
        c = base[rng() % 2];
    return st;
}
int brute(const string& st) {
    int n = st.size(), k = -1;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int len = j - i + 1, reps = 0;
            string cur = st.substr(i, len);
            while (st.substr(len * reps + i, len) == cur)
                reps++;
            k = max(k, reps);
        }
    }
    return k;
}
vector<set<int>> comp;
vector<int> siz, par;
int root(int a) {
    if (par[a] == -1) par[a] = a;
    int _a = a;
    while (a != par[a]) a = par[a];
    par[_a] = a;
    return a;
}
int add(int a, int b) {
    int ret = 1e9;
    a = root(a);
    b = root(b);
    if (a == b) return ret;
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b];
    par[b] = a;
    for (int x : comp[b]) {
        auto it = comp[a].lb(x);
        if (it != comp[a].end()) ret = min(ret, abs(*it - x));
        if (it != comp[a].begin()) ret = min(ret, abs(*(--it) - x));
    }
    for (int x : comp[b]) comp[a].insert(x);
    comp[b].clear();
    return ret;
}
int solve(const string& _) {
    suf_array s;
    s.build(_);
    int mx = *max_element(all(s.base_lcp)) + 1;
    vector<vector<int>> idx(mx);
    for (int i = 0; i < s.n; i++)
        idx[s.base_lcp[i]].eb(i);
    par.assign(s.n, -1);
    siz.assign(s.n, 1);
    comp.clear();
    comp.resize(s.n);
    for (int i = 0; i < s.n; i++)
        comp[i].insert(s.p[i]);
    int ans = 1;
    for (int i = mx - 1; i > 0; i--) {
        for (int j : idx[i]) {
            int cur = add(j, j - 1);
            assert(cur);
            ans = max(ans, 1 + i / cur);
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        string st;
        // st = gen_random(10);
        cin >> st;
        // trace(st);
        int my_ans = solve(st);
        cout << my_ans << '\n';
        // int brute_ans = brute(st);
        // if (my_ans != brute_ans)
        //     trace(my_ans, brute_ans);
    }
}
