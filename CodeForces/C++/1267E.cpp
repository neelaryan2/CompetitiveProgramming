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
    int n, m;
    cin >> n >> m;
    int a[m][n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    vector<int> ans(m + 1);

    for (int i = 0; i < n - 1; i++) {
        vector<pii> cur;
        for (int j = 0; j < m; j++) {
            int d = a[j][i] - a[j][n - 1];
            cur.eb(d, j + 1);
        }

        sort(rall(cur));
        for (int j = 1; j < m; j++)
            cur[j].fi += cur[j - 1].fi;

        int ptr = 0;
        while (ptr < m && cur[ptr].fi >= 0)
            ptr++;

        if (m - ptr < ans.size()) {
            ans.clear();
            while (ptr < m)
                ans.eb(cur[ptr++].se);
        }
    }
    sort(all(ans));
    cout << ans.size() << '\n';
    for (int i : ans)
        cout << i << ' ';
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
