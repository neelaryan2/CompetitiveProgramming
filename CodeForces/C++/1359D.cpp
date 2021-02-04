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
const int inf = 1e9;
ll getMax(vi& a, int val) {
    int n = a.size();
    vector<int> ind;
    for (int i = 0; i < n; i++) {
        if (a[i] == val) ind.pb(i);
    }
    if (ind.empty()) return -inf;
    if (n == 1) return 0;
    ll ans = -inf;
    vector<ll> p(n + 1, 0);
    vector<ll> mn(n + 1, 0);
    for (int i = 0; i < n; i++) {
        p[i + 1] = p[i] + a[i];
        mn[i + 1] = min(mn[i], p[i + 1]);
    }
    for (int i = 1; i <= n; i++) {
        int j = ub(all(ind), i - 1) - ind.begin();
        if (j == 0) continue;
        j = ind[j - 1];
        ans = max(ans, p[i] - mn[j]);
    }
    return ans - val;
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    ll ans = 0;
    for (int val = 30; val >= -30; val--) {
        vector<int> ind(1, -1);
        for (int i = 0; i < n; i++)
            if (a[i] > val) ind.pb(i);
        ind.pb(n);
        for (int i = 1; i < ind.size(); i++) {
            vector<int> tmp;
            for (int j = ind[i - 1] + 1; j < ind[i]; j++)
                tmp.pb(a[j]);
            ll cur = getMax(tmp, val);
            if (cur == -inf) continue;
            trace(tmp, cur, val);
            ans = max(ans, cur);
        }
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    while (t--) solve();
}
