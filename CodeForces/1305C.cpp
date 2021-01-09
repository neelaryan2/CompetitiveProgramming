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
    vector<int> a(n);
    for (int& e : a)
        cin >> e;
    if (n > m) {
        cout << 0;
        return;
    }
    int ans = 1, cur;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            cur = abs(a[j] - a[i]) % m;
            ans = (ans * cur) % m;
        }
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
