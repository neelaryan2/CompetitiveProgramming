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
const int inf = 1e9;

void solve(int test) {
    int n, m;
    string s;
    cin >> n >> m >> s;
    vector<bool> plis(n + 2, false);

    int ans = 0;

    for (int i = 0; i < n; i++)
        plis[i + 1] = (s[i] == '.');

    for (int i = 0; i < n; i++) {
        if (s[i] != '.') continue;
        int l = i;
        while (s[i] == '.') i++;
        ans += (--i) - l;
    }
    trace(ans);
    for (int i = 0; i < m; i++) {
        int j;
        string c;
        cin >> j >> c;
        bool cur = (c[0] == '.');
        if (plis[j] != cur) {
            if (cur) {
                if (plis[j + 1]) ans++;
                if (plis[j - 1]) ans++;
            } else {
                if (plis[j + 1]) ans--;
                if (plis[j - 1]) ans--;
            }
            plis[j] = cur;
        }
        cout << ans << '\n';
    }
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
    }
}
