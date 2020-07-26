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
    int x;
    cin >> x;
    int ans;
    if (x < 600)
        ans = 8;
    else if (x < 800)
        ans = 7;
    else if (x < 1000)
        ans = 6;
    else if (x < 1200)
        ans = 5;
    else if (x < 1400)
        ans = 4;
    else if (x < 1600)
        ans = 3;
    else if (x < 1800)
        ans = 2;
    else if (x < 2000)
        ans = 1;
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
        cout << "\n";
    }
}
