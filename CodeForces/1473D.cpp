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

const int inf = 1e8 + 7;

void solve(int test) {
    int n, m;
    string s;
    cin >> n >> m >> s;
    vector<int> p(n + 1, 0);

    vector<int> mnl(n + 1, inf), mxl(n + 1, -inf);
    mnl[0] = mxl[0] = p[0];
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1];
        if (s[i - 1] == '+') p[i]++;
        if (s[i - 1] == '-') p[i]--;
        mnl[i] = min(mnl[i - 1], p[i]);
        mxl[i] = max(mxl[i - 1], p[i]);
    }

    vector<int> mnr(n + 1, inf), mxr(n + 1, -inf);
    mnr[n] = mxr[n] = p[n];
    for (int i = n - 1; i >= 0; i--) {
        mnr[i] = min(mnr[i + 1], p[i]);
        mxr[i] = max(mxr[i + 1], p[i]);
    }
    trace(p);
    trace(mnl, mnr);
    trace(mxl, mxr);
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        int delta = p[r] - p[l - 1];
        int downl = mnl[l - 1], upl = mxl[l - 1];
        trace(l, r, delta);
        if (r == n) {
            cout << (upl - downl + 1) << '\n';
            continue;
        }
        int downr = mnr[r + 1], upr = mxr[r + 1];
        trace(downl, upl, downr, upr);
        downr -= delta, upr -= delta;
        int idown = max(downl, downr);
        int iup = min(upl, upr);

        int ans = (upl - downl) + (upr - downr) + 2;
        ans -= max(0, iup - idown + 1);

        cout << ans << '\n';
    }
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
        // cout << '\n';
    }
}
