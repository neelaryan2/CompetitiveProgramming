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
    ll n, k;
    string s;
    cin >> n >> k >> s;
    vector<int> v(1, -1);
    for (int i = 0; i < n; i++)
        if (s[i] == '0') v.eb(i);
    for (int i = 1; i < v.size(); i++) {
        int t = min(k, (ll)v[i] - v[i - 1] - 1);
        v[i] -= t, k -= t;
    }
    string ans(n, '1');
    for (int i = 1; i < v.size(); i++)
        ans[v[i]] = '0';
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
