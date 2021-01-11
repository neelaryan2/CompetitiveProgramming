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
    int n, t;
    ld pp, ans = 0;
    cin >> n >> pp >> t;

    vector<ld> p(t + 1, 1), q(t + 1, 1);
    for (int i = 1; i <= t; i++) {
        p[i] = p[i - 1] * pp;
        q[i] = q[i - 1] * (1 - pp);
    }

    for (int i = 1; i <= min(t, n - 1); i++) {
        ld cur = 1;
        int cnt = t - i;
        for (int j = 1; j <= i; j++) {
            cur *= (t - j + 1) * pp;
            if (cnt) cur *= (1 - pp), cnt--;
            cur /= j;
        }
        while (cnt > 0) cur *= (1 - pp), cnt--;
        ans += cur * i;
    }
    for (int i = n; i <= t; i++) {
        ld cur = pp;
        int cnt = i - n;
        for (int j = 1; j <= n - 1; j++) {
            cur *= (i - j) * pp;
            if (cnt) cur *= (1 - pp), cnt--;
            cur /= j;
        }
        while (cnt > 0) cur *= (1 - pp), cnt--;
        ans += cur * n;
    }
    cout << fixed << setprecision(15) << ans;
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
