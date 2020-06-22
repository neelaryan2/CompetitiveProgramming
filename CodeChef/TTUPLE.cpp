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
using vi = vector<ll>;
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
const int inf = 1e9;
int p, q, r;
int a, b, c;
ll gcd(ll n1, ll n2) {
    if (n1 == 0) return n2;
    if (n2 == 0) return n1;
    return __gcd(abs(n1), abs(n2));
}
bool check0(vi v1, vi v2) {
    int t = v1.size();
    for (int i = 0; i < t; i++)
        if (v2[i] != v1[i])
            return false;
    return true;
}
bool check1(vi v1, vi v2) {
    int t = v1.size();
    set<ll> s;
    for (int i = 0; i < t; i++)
        if (v2[i] != v1[i])
            s.insert(v2[i] - v1[i]);
    if (s.size() <= 1)
        return true;
    s.clear();
    for (int i = 0; i < t; i++) {
        if (v2[i] == v1[i]) continue;
        if (v1[i] == 0) return false;
        if (v2[i] % v1[i]) return false;
        s.insert(v2[i] / v1[i]);
    }
    return (s.size() <= 1);
}
void getFactors(ll num, vi& div) {
    div.clear();
    num = abs(num);
    for (int i = 1; 1LL * i * i <= num; i++) {
        if (num % i) continue;
        div.pb(i), div.pb(-i);
        if (i * i == num) break;
        div.pb(num / i), div.pb(-num / i);
    }
    sort(all(div));
}
int solve() {
    if (check0({p, q, r}, {a, b, c})) return 0;
    if (check1({p, q, r}, {a, b, c})) return 1;
    if (check1({p, q}, {a, b})) return 2;
    if (check1({q, r}, {b, c})) return 2;
    if (check1({r, p}, {c, a})) return 2;
    if (check1({0, 0, r}, {a, b, c})) return 2;
    if (check1({p, 0, 0}, {a, b, c})) return 2;
    if (check1({0, q, 0}, {a, b, c})) return 2;
    if (check1({0, 0, 0}, {a, b, c})) return 2;
    vi inp = {p, q, r, p, q, r};
    vi tar = {a, b, c, a, b, c};
    // only add
    vi dif = {a - p, b - q, c - r};
    for (int i = 0; i < 3; i++) {
        ll s = dif[i] + dif[(i + 1) % 3];
        if (dif[(i + 2) % 3] == s) return 2;
    }
    // only muliply
    vi quo;
    if (p != 0 && a % p == 0) quo.pb(a / p);
    if (q != 0 && b % q == 0) quo.pb(b / q);
    if (r != 0 && c % r == 0) quo.pb(c / r);
    if (quo.size() == 3) {
        for (int i = 0; i < 3; i++) {
            ll s = 1LL * quo[i] * quo[(i + 1) % 3];
            if (quo[(i + 2) % 3] == s) return 2;
        }
    }
    // add, then multiply
    vi factors;
    for (int i = 0; i < 3; i++) {
        ll tp = inp[i], tq = inp[i + 1], tr = inp[i + 2];
        ll ta = tar[i], tb = tar[i + 1], tc = tar[i + 2];
        ll g = gcd(tb, tc);
        getFactors(g, factors);
        for (ll d : factors) {
            if (check1({tp, tq, tr}, {ta, tb / d, tc / d})) return 2;
        }
        getFactors(ta, factors);
        for (ll d : factors) {
            if (check1({tp, tq, tr}, {ta / d, tb, tc})) return 2;
        }
        if (i == 0) {
            g = gcd(ta, gcd(tb, tc));
            getFactors(g, factors);
            for (ll d : factors) {
                if (check1({tp, tq, tr}, {ta / d, tb / d, tc / d})) return 2;
            }
        }
    }
    // multiply and add
    for (int i = 0; i < 3; i++) {
        ll tp = inp[i], tq = inp[i + 1], tr = inp[i + 2];
        ll ta = tar[i], tb = tar[i + 1], tc = tar[i + 2];
        getFactors(ta, factors);
        for (ll d : factors) {
            ll pp = tp * d, qq = tq * d, rr = tr * d;
            if (check1({pp, qq, tr}, {ta, tb, tc})) return 2;
            if (check1({pp, tq, rr}, {ta, tb, tc})) return 2;
            if (check1({pp, qq, rr}, {ta, tb, tc})) return 2;
        }
        getFactors(abs(ta - tb), factors);
        for (ll d : factors) {
            ll pp = tp * d, qq = tq * d, rr = tr * d;
            if (check1({pp, qq, tr}, {ta, tb, tc})) return 2;
            if (check1({pp, qq, rr}, {ta, tb, tc})) return 2;
        }
    }
    return 3;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        cin >> p >> q >> r;
        cin >> a >> b >> c;
        int ans = solve();
        cout << ans << '\n';
    }
}
