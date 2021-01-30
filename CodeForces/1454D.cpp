#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using ld = long double;
using pii = pair<ll, int>;
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

vector<pii> fac;

void factorize(ll n) {
    fac.clear();
    int cnt = 0;
    while (n % 2 == 0)
        cnt++, n >>= 1;
    if (cnt) fac.eb(2, cnt);
    for (int i = 3; 1LL * i * i <= n; i += 2) {
        cnt = 0;
        while (n % i == 0)
            cnt++, n /= i;
        if (cnt) fac.eb(i, cnt);
    }
    if (n > 2) fac.eb(n, 1);
}
void solve(int test) {
    ll n;
    cin >> n;
    factorize(n);
    int m = fac.size(), k = -1;
    for (pii& p : fac)
        k = max(k, p.se);

    vector<ll> ans(k, 1);
    for (pii& p : fac) {
        int i = k;
        while (p.se--)
            ans[--i] *= p.fi;
    }

    cout << k << '\n';
    for (ll i : ans)
        cout << i << ' ';
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
        cout << '\n';
    }
}
