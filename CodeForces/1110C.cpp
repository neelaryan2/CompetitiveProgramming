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
    int a, cur = -1;
    cin >> a;
    if ((a & (a + 1)) == 0) {
        for (int i = 1; i * i <= a; i++) {
            if (a % i) continue;
            cur = max(cur, i);
            if (i != 1) cur = max(cur, a / i);
        }
    } else {
        for (int i = 0; i < 25; i++)
            if ((a >> i) & 1)
                cur = (1 << (i + 1)) - 1;
        assert(cur != -1);
    }
    cout << cur << '\n';
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
