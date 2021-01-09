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

void solve(int test) {
    int n;
    cin >> n;
    vector<int> w(n);
    for (int& e : w) cin >> e;
    int ans = 0;
    for (int s = 2; s <= 2 * n; s++) {
        int cur = 0;
        vector<int> cnt(n + 1, 0);
        for (int& e : w) cnt[e]++;
        trace(cnt);
        for (int i = max(s - n, 0); i <= min(s, n); i++) {
            int mn = min(cnt[i], cnt[s - i]);
            if (i == s - i) mn /= 2;
            cur += mn;
            cnt[i] -= mn, cnt[s - i] -= mn;
            trace(s, mn);
        }
        ans = max(ans, cur);
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
        cout << '\n';
    }
}
