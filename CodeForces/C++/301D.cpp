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
    vector<int> pos(n), p(n);
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        pos[e - 1] = i;
        p[i] = e;
    }
    vector<ppi> q1(m), q2(m);
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        q1[i] = mp(mp(l, r), i);
        q2[i] = mp(mp(r, l), i);
    }
    sort(all(q1));
    sort(all(q2));
    int k1 = 0, k2 = 0;
    vector<int> ans(m), B(n + 10, 0);
    for (int i = 0; i < n; i++) {
        int cur = p[i];
        while (k1 < m && q1[k1].fi.fi == i) {
            ans[q1[k1].se] -= sum(B, q1[k1].fi.se + 1) - sum(B, i);
            k1++;
        }
        for (int j = cur; j <= n; j += cur)
            add(B, pos[j - 1] + 1, 1);
        while (k2 < m && q2[k2].fi.fi == i) {
            ans[q2[k2].se] += sum(B, i + 1) - sum(B, q2[k2].fi.se);
            k2++;
        }
    }
    for (int i : ans) cout << i << '\n';
}
