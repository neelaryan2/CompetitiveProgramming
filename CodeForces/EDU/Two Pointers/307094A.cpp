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
    ll n, p, tot = 0;
    cin >> n >> p;
    vector<int> a(n);
    for (int& e : a) {
        cin >> e;
        tot += e;
    }
    ll ans = (p / tot) * n;
    p %= tot;

    for (int i = 0; i < n; i++)
        a.eb(a[i]);

    ll sum = 0;
    int ptr = 0, cur = n, st = 1;
    for (int i = 0; i < n; i++) {
        while (ptr < 2 * n && sum < p)
            sum += a[ptr++];
        if (sum >= p && ptr - i <= cur) {
            cur = ptr - i;
            st = i + 1;
        }
        sum -= a[i];
    }
    ans += cur;
    cout << st << ' ' << ans;
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
