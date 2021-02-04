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

void solve(int test) {
    string s;
    cin >> s;
    int n = s.size(), ans = 0;
    for (int i = 0; i < n; i++) {
        int l = 0, r = 0;
        for (int j = i; j < n; j++) {
            if (s[j] == ')') l--, r--;
            if (s[j] == '(') l++, r++;
            if (s[j] == '?') l--, r++;
            if (r < 0) break;
            if (l < 0) l += 2;
            if (l == 0) ans++;
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
