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
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
vector<int> a;
int solve(int t) {
    trace(t);
    int n = a.size(), mn = 1e9;
    vector<int> dp(n, 0);
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = n - i - 1;
        for (int j = i + 1; j < n; j++) {
            int cur = abs(a[j] - a[i]);
            if (cur <= 1LL * (j - i) * t)
                dp[i] = min(dp[i], j - i - 1 + dp[j]);
        }
        mn = min(mn, dp[i] + i);
    }
    trace(dp);
    return mn;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    a.resize(n);
    for (int& e : a) cin >> e;
    int lo = -1, hi = 2e9, mid;
    while (lo < hi - 1) {
        mid = lo + (hi - lo) / 2;
        if (solve(mid) <= k)
            hi = mid;
        else
            lo = mid;
    }
    cout << hi << '\n';
}
