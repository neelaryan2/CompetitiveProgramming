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
using ppi = pair<int, int>;
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
    int pt = 0, pl = m, pr = m;
    bool flag = true;
    for (int i = 0; i < n; i++) {
        int t, l, r;
        cin >> t >> l >> r;
        pl = max(pl - t + pt, l);
        pr = min(pr + t - pt, r);
        pt = t;
        if (pl > pr) flag = false;
    }
    puts(flag ? "YES" : "NO");
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
