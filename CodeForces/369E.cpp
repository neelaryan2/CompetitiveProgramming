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
using ppi = pair<pii, int>;
using vi = vector<int>;
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
void add(vector<int>& B, int i, int x) {
    int n = B.size();
    for (; i < n; i += i & (-i))
        B[i] = B[i] + x;
}
int sum(vector<int>& B, int i) {
    int sum = 0;
    for (; i > 0; i -= i & (-i))
        sum = sum + B[i];
    return sum;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    const int N = 1e6 + 10;
    vector<pii> segs(n);
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        segs[i] = mp(u, v);
    }
    sort(all(segs), [](pii a, pii b) {
        if (a.se != b.se)
            return a.se < b.se;
        else
            return a.fi < b.fi;
    });
    vector<ppi> vec;
    vector<int> ans(m, n);
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        vector<int> tmp(k);
        for (int j = 0; j < k; j++)
            cin >> tmp[j];
        tmp.pb(0);
        tmp.pb(N - 1);
        sort(all(tmp));
        for (int j = 1; j <= k + 1; j++) {
            pii p = mp(tmp[j - 1], tmp[j]);
            vec.pb(mp(p, i));
        }
    }
    sort(all(vec), [](ppi a, ppi b) {
        if (a.fi.se != b.fi.se)
            return a.fi.se < b.fi.se;
        else
            return a.fi.fi < b.fi.fi;
    });
    int q = vec.size(), ind = 0;
    trace(segs);
    vector<int> B(N, 0);
    for (int i = 0; i < q; i++) {
        ppi p = vec[i];
        while (ind < n && segs[ind].se < p.fi.se) {
            add(B, segs[ind].fi, 1);
            ind++;
        }
        int cur = ind - sum(B, p.fi.fi);
        trace(p, cur);
        ans[p.se] -= cur;
    }
    for (int i : ans) cout << i << '\n';
}
