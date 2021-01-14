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
const string st = "BSC";
const int k = st.size();

void solve(int test) {
    int n;
    cin >> n;
    vector<ll> x(n), v(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> v[i];

    auto check = [&](ld t) {
        ld lef = x[0] - t * v[0];
        ld righ = x[0] + t * v[0];
        for (int i = 1; i < n; i++) {
            lef = max(lef, x[i] - t * v[i]);
            righ = min(righ, x[i] + t * v[i]);
        }
        return lef <= righ;
    };

    ld l = 0, r = 1e13, mid;
    for (int i = 0; i < 100; i++) {
        mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    cout << setprecision(16) << r << '\n';
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
