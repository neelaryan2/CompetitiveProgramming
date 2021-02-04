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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    int n = s.size();
    bool is_pal[n][n];
    for (int l = n - 1; l >= 0; l--) {
        for (int r = n - 1; r >= 0; r--) {
            int len = r - l + 1;
            if (len < 0) {
                is_pal[l][r] = false;
            } else if (len < 2) {
                is_pal[l][r] = true;
            } else {
                is_pal[l][r] = (s[l] == s[r]) && is_pal[l + 1][r - 1];
            }
        }
    }
    ll num_pal[n];
    num_pal[0] = 1;
    for (int i = 1; i < n; i++) {
        num_pal[i] = num_pal[i - 1];
        for (int j = i; j >= 0; j--)
            if (is_pal[j][i]) num_pal[i]++;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j > 0; j--) {
            if (is_pal[j][i]) {
                ans += num_pal[j - 1];
            }
        }
    }
    cout << ans << '\n';
}
