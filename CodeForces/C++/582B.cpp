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
const int A = 310;
void solve(vector<int>& a, vector<int>& dp) {
    int n = a.size(), t;
    vector<int> s(n + 1, inf);
    s[0] = -inf;
    fill(all(dp), 0);
    for (int i : a) {
        int j = ub(all(s), i) - s.begin();
        s[j] = i, t = abs(s[j]);
        dp[t] = max(dp[t], j);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, t;
    cin >> n >> t;
    vector<int> dp1(A), dp2(A);
    if (t <= 2 * n) {
        vector<int> a(n * t);
        for (int i = 0, e; i < n; i++) {
            cin >> e;
            for (int j = i; j < n * t; j += n)
                a[j] = e;
        }
        solve(a, dp1);
        int mx = *max_element(all(dp1));
        cout << mx << '\n';
        return 0;
    }
    vector<int> a(n * n), cnt(A, 0);
    for (int i = 0, e; i < n; i++) {
        cin >> e;
        cnt[e]++;
        for (int j = i; j < n * n; j += n)
            a[j] = e;
    }
    solve(a, dp1);
    for (int& e : a) e = -e;
    reverse(all(a));
    solve(a, dp2);
    int ans = 0;
    for (int i = 0; i < A; i++) {
        if (cnt[i] == 0) continue;
        ans = max(ans, (t - 2 * n) * cnt[i] + dp1[i] + dp2[i]);
    }
    cout << ans << '\n';
}
