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
    int n, k;
    cin >> n >> k;
    vector<string> g(n, string(n, '0'));
    int val = (k % n) ? 2 : 0;
    for (int len = 0; len <= n - 1 && k; len++)
        for (int i = 0; i < n && k; i++)
            g[i][(i + len) % n] = '1', k--;
    cout << val << '\n';
    for (int i = 0; i < n; i++)
        cout << g[i] << '\n';
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
