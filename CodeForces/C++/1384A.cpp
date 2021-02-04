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
    vector<int> a(n);
    for (int& e : a) cin >> e;
    vector<string> ans(n + 1);
    for (int i = 0; i < 52; i++)
        ans[0] += 'a';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < a[i]; j++)
            ans[i + 1] += ans[i][j];
        char nc = 'a';
        for (int ch = 0; ch < 26; ch++)
            if (ans[i][a[i]] - 'a' != ch) {
                nc = ch + 'a';
                break;
            }
        for (int j = a[i]; j < 52; j++)
            ans[i + 1] += nc;
    }
    for (int i = 0; i <= n; i++)
        cout << ans[i] << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve(i);
        // cout << "\n";
    }
}
