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
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
vector<int> cnt;
int zero = 0;
void add(int& num, int x) {
    int& res = cnt[num];
    if (res == 0) zero--;
    res += x;
    if (res == 0) zero++;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    int rt = 1 + (m * 1.0) / sqrtl(n);
    vector<int> a(n), vec;
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        a[i] = e;
        vec.pb(e);
    }
    sort(all(vec));
    int sz = distance(vec.begin(), unique(all(vec)));
    vec.resize(sz);
    cnt.resize(sz);
    map<int, int> comp;
    for (int i = 0; i < sz; i++) {
        comp[vec[i]] = i;
        cnt[i] = -vec[i];
    }
    for (int i = 0; i < n; i++)
        a[i] = comp[a[i]];
    vector<ppi> q(m);
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        q[i] = {{l, r}, i};
    }
    sort(all(q), [rt](ppi a, ppi b) {
        if (a.fi.fi / rt != b.fi.fi / rt)
            return a.fi.fi / rt < b.fi.fi / rt;
        else
            return a.fi.se < b.fi.se;
    });
    vector<int> ans(m);
    int L = 0, R = -1;
    for (ppi p : q) {
        int l = p.fi.fi;
        int r = p.fi.se;
        int i = p.se;
        while (R < r) add(a[++R], 1);
        while (L < l) add(a[L++], -1);
        while (R > r) add(a[R--], -1);
        while (L > l) add(a[--L], 1);
        ans[i] = zero;
    }
    for (int i : ans) cout << i << '\n';
}
