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

void solve(int test) {
    int n, d, m;
    cin >> n >> d >> m;
    vector<ll> a[2];
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        a[e > m].eb(e);
    }
    for (int j : {0, 1}) {
        sort(rall(a[j]));
        a[j].insert(a[j].begin(), 0);
        for (int i = 1; i < a[j].size(); i++)
            a[j][i] += a[j][i - 1];
    }
    ll ans = 0;
    for (int i = 0; i < a[0].size(); i++) {
        int j = 1 + (n - i - 1) / (d + 1);
        if (i == n) j = 0;
        if (j >= a[1].size()) continue;
        ans = max(ans, a[0][i] + a[1][j]);
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
        solve(i);
        cout << '\n';
    }
}
