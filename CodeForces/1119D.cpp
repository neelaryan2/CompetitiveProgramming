/* Author - Neel Aryan (@neelaryan2) */
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<ll> s(n);
    for (ll& e : s) cin >> e;
    sort(all(s));
    n = distance(s.begin(), unique(all(s)));
    s.resize(n);
    ll ans = s[n - 1] - s[0], res;
    for (int i = 0; i < n - 1; i++)
        s[i] = s[i + 1] - s[i];
    s.pop_back(), n--;
    sort(all(s));
    vector<ll> suf(n + 1, 0);
    trace(suf);
    for (int i = n - 1; i >= 0; i--)
        suf[i] = suf[i + 1] + s[i];
    int m;
    cin >> m;
    trace(suf);
    for (int i = 0; i < m; i++) {
        ll l, r;
        cin >> l >> r;
        int j = ub(all(s), r - l) - s.begin();
        res = 1LL * (n - j + 1) * (r - l + 1);
        res += ans - suf[j];
        cout << res << ' ';
    }
    cout << '\n';
}
