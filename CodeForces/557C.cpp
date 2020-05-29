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
const int N = 1e5 + 5;
vi cnt(205, 0);
map<int, vi> dp;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> cnt(N, 0);
    vector<int> l(n);
    for (int i = 0; i < n; i++)
        cin >> l[i];
    int sum = 0, cost = 0, ans = 1e9;
    for (int i = 0, d; i < n; i++) {
        cin >> d;
        dp[l[i]].pb(d);
        cost += d;
    }
    for (auto p : dp) {
        int k = p.se.size(), cur = 0;
        int need = max(sum + 1 - k, 0);
        for (int j = 1; need && j <= 200; j++) {
            if (cnt[j] == 0) continue;
            int t = min(need, cnt[j]);
            need -= t, cur += t * j;
        }
        for (int j : p.se) {
            cnt[j]++;
            cost -= j;
        }
        sum += k;
        trace(p.fi, p.se, cur, cost);
        ans = min(ans, cur + cost);
    }
    cout << ans << '\n';
}
