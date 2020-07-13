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
using ppi = pair<pii, int>;
using vi = vector<int>;
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
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
    int n;
    cin >> n;
    vector<pii> vec(n, mp(-1, -1));
    for (int i = 0; i < 2 * n; i++) {
        int e;
        cin >> e;
        pii& p = vec[e - 1];
        p.se = i + 1;
        if (p.fi == -1) p.fi = i + 1;
    }
    vector<ppi> seg(n);
    vector<int> rs(2 * n + 10, 0);
    for (int i = 0; i < n; i++) {
        seg[i].fi = vec[i];
        seg[i].se = i;
    }
    sort(all(seg));
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ppi& p = seg[i];
        ans[p.se] = sum(rs, p.fi.se) - sum(rs, p.fi.fi);
        add(rs, p.fi.se, 1);
    }
    for (int i = 0; i < n; i++) {
        ppi& p = seg[i];
        add(rs, p.fi.se, -1);
        int j = lb(seg.begin() + i + 1, seg.end(), mp(mp(p.fi.se, -1), -1)) - seg.begin();
        ans[p.se] += j - i - 1 - sum(rs, p.fi.se) + sum(rs, p.fi.fi);
    }
    for (int i : ans) cout << i << ' ';
    cout << '\n';
}
