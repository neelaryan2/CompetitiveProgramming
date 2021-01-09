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
    int a[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    for (int b = 0; b < 10; b++) {
        vector<pii> ans;
        int cur = 0, partial = -1;
        for (int i = 0; i < n; i++) {
            int oneid = -1, zeroid = -1;
            for (int j = 0; j < m; j++) {
                int bit = (a[i][j] >> b) & 1;
                if (bit)
                    oneid = j + 1;
                else
                    zeroid = j + 1;
            }
            if (oneid == -1 || zeroid == -1) {
                ans.eb(mp(1, -1));
                cur ^= (zeroid == -1);
            } else {
                ans.eb(mp(zeroid, oneid));
                partial = i;
            }
        }
        if (cur) {
            cout << "TAK\n";
            for (pii p : ans)
                cout << p.fi << ' ';
            return;
        }
        if (partial != -1) {
            swap(ans[partial].fi, ans[partial].se);
            cout << "TAK\n";
            for (pii p : ans)
                cout << p.fi << ' ';
            return;
        }
    }
    cout << "NIE";
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
