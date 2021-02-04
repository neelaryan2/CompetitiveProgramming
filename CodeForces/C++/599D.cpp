/* Author - Neel Aryan (@neelaryan2) */
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = unsigned long long;
using ld = long double;
using pii = pair<ll, ll>;
using vi = vector<int>;
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll x = 8;
    cin >> x;
    ll val = 0, a = 0;
    while (val <= x) {
        val += a * a;
        a++;
    }
    set<pii> ans;
    for (ll i = 1; i < a; i++) {
        ll res = (i * (i + 1)) / 2;
        ll cur = (res * (i - 1)) / 3;
        if ((x + cur) % res) continue;
        auto p = mp(i, (x + cur) / res);
        ans.insert(p);
        if (p.fi == p.se) continue;
        swap(p.fi, p.se);
        ans.insert(p);
    }
    cout << ans.size() << '\n';
    for (pii p : ans)
        cout << p.fi << ' ' << p.se << '\n';
}
