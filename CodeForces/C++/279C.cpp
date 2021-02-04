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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), dpL(n, 0), dpR(n, n - 1);
    for (int& e : a) cin >> e;
    for (int i = 1; i < n; i++)
        dpL[i] = (a[i] <= a[i - 1]) ? dpL[i - 1] : i;
    for (int i = n - 2; i >= 0; i--)
        dpR[i] = (a[i] <= a[i + 1]) ? dpR[i + 1] : i;
    for (int _ = 0; _ < m; _++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        bool b = dpL[r] <= dpR[l];
        puts(b ? "Yes" : "No");
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
