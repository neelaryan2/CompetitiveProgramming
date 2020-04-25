#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ld long double
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
#define S second
#define F first
#define f(i, j, k, l) for (ll i = (ll)j; i != (ll)k; i = i + l)
#define endl '\n'

ld a, b, c;
ld ycal(ll x) {
    return (-c - a * x) / b;
}
ld xcal(ll y) {
    return (-c - b * y) / a;
}
ld di(pld p1, pld p2) {
    ld t1 = p1.F - p2.F;
    ld t2 = p1.S - p2.S;
    return sqrtl(t1 * t1 + t2 * t2);
}
ld man(pll p1, pll p2) {
    ld t1 = p1.F - p2.F;
    ld t2 = p1.S - p2.S;
    return sqrtl(t1 * t1 + t2 * t2);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll x1, y1, x2, y2;
    cin >> a >> b >> c >> x1 >> y1 >> x2 >> y2;
    ld dis = abs(x2 - x1) + abs(y2 - y1);
    if (a == 0 || b == 0) {
        cout << fixed << setprecision(10) << dis << endl;
        return 0;
    }
    vector<pair<ld, ld>> v1(2), v2(2), v(4);
    v1[0] = {x1, ycal(x1)};
    v2[0] = {x2, ycal(x2)};
    v1[1] = {xcal(y1), y1};
    v2[1] = {xcal(y2), y2};
    v[0] = v1[0];
    v[1] = v1[1];
    v[2] = v2[0];
    v[3] = v2[1];
    sort(v.begin(), v.end());
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    if ((v[0] == v1[0] && v[1] == v1[1]) || (v[0] == v2[0] && v[1] == v2[1])) {
        dis += di(v[1], v[2]) - (abs(v[1].F - v[2].F) + abs(v[1].S - v[2].S));
    }

    cout << fixed << setprecision(10) << dis << endl;
}