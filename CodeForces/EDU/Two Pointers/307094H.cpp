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
    int n, m, s, A, B;
    cin >> n >> m >> s >> A >> B;
    vector<ll> a(n), b(m);

    for (ll& e : a) cin >> e;
    sort(rall(a));
    a.insert(a.begin(), 0);
    for (int i = 1; i <= n; i++)
        a[i] += a[i - 1];

    for (ll& e : b) cin >> e;
    sort(rall(b));
    b.insert(b.begin(), 0);
    for (int i = 1; i <= m; i++)
        b[i] += b[i - 1];

    trace(a, b);
    ll weight = 1LL * m * B, ans = 0;
    int ptr = m;
    for (int i = 0; i <= n; i++) {
        while (ptr > 0 && weight > s)
            weight -= B, ptr--;
        if (weight <= s)
            ans = max(ans, a[i] + b[ptr]);
        weight += A;
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
