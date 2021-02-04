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
const int N = 31;
const ll inf = 1e18;
void solve(int test) {
    int k;
    string s;
    cin >> k >> s;
    int n = s.size();
    vector<int> idx(1, -1);
    for (int i = 0; i < n; i++)
        if (s[i] == '1')
            idx.eb(i);
    idx.eb(n);
    n = idx.size() - 2;
    ll ans = 0, cur;
    if (k == 0) {
        for (int i = 1; i < n + 2; i++) {
            cur = idx[i] - idx[i - 1] - 1;
            ans += (cur * (cur + 1)) / 2;
        }
    } else {
        for (int i = k; i <= n; i++) {
            cur = idx[i - k + 1] - idx[i - k];
            cur *= idx[i + 1] - idx[i];
            ans += cur;
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