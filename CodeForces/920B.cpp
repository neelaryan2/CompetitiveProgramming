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
    vector<int> ans(n, 0), l(n), r(n);
    for (int i = 0; i < n; i++)
        cin >> l[i] >> r[i];
    int cur = l[0] + 1;
    ans[0] = l[0];
    for (int i = 1; i < n; i++) {
        if (r[i] < cur) continue;
        ans[i] = max(l[i], cur);
        cur = ans[i] + 1;
    }
    for (int& i : ans) cout << i << ' ';
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
