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

ll lcm(int x, int y) {
    return (1LL * x * y) / __gcd(x, y);
}
void solve(int test) {
    int n, k, e;
    ll cur = 1;
    cin >> n >> k;
    while (n--) {
        cin >> e;
        cur = lcm(cur, __gcd(e, k));
        if (cur > k) {
            cout << "No";
            return;
        }
    }
    if (cur == k)
        cout << "Yes";
    else
        cout << "No";
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
