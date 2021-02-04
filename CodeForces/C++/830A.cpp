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
#define rall(v) (v).rbegin(), (v).rend()

const int inf = 1e9 + 7;

void solve(int test) {
    int n, k, p;
    cin >> n >> k >> p;
    vector<int> a(n), b(k);
    for (int& e : a) cin >> e;
    for (int& e : b) cin >> e;
    sort(all(a)), sort(all(b));
    ll ans = LLONG_MAX;
    for (int i = 0; i + n <= k; i++) {
        ll cur = 0;
        for (int j = i; j < i + n; j++)
            cur = max(cur, (ll)abs(b[j] - a[j - i]) + abs(b[j] - p));
        ans = min(ans, cur);
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve(i);
        cout << '\n';
    }
}
