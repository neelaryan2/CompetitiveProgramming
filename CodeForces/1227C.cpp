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
    int n, k;
    string s, t;
    cin >> n >> k >> s;
    for (int i = 1; i < k; i++) {
        t.pb('(');
        t.pb(')');
    }
    int ex = n / 2 - k + 1;
    for (int i = 0; i < ex; i++)
        t.pb('(');
    for (int i = 0; i < ex; i++)
        t.pb(')');
    trace(s, t);
    vector<pii> ans;
    for (int i = 0; i < n; i++) {
        if (s[i] == t[i]) continue;
        for (int j = i + 1; j < n; j++)
            if (s[j] == t[i]) {
                ans.eb(i + 1, j + 1);
                int len = (j - i + 1);
                trace(s, i, j);
                for (int k = 0; k < len / 2; k++)
                    swap(s[i + k], s[j - k]);
                trace(s);
                break;
            }
    }
    cout << ans.size() << '\n';
    for (pii p : ans)
        cout << p.fi << ' ' << p.se << '\n';
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
    }
}
