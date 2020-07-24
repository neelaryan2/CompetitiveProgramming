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
const string base = "RGB";
void solve(int test) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int sz = base.size();
    int ans = 1e9;
    for (int off : {0, 1, 2}) {
        for (int i = 0; i <= n - k; i++) {
            int cur = 0;
            for (int j = 0; j < k; j++) {
                char c = base[(j + off) % sz];
                if (s[j + i] != c) cur++;
            }
            ans = min(ans, cur);
        }
    }
    cout << ans << '\n';
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
