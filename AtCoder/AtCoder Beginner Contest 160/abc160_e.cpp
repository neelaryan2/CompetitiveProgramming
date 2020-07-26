#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<ll> p(a), q(b), r(c);
    for (ll& e : p) cin >> e;
    for (ll& e : q) cin >> e;
    for (ll& e : r) cin >> e;
    sort(p.rbegin(), p.rend());
    while (p.size() > x) p.pop_back();
    sort(q.rbegin(), q.rend());
    while (q.size() > y) q.pop_back();
    sort(r.rbegin(), r.rend());
    while (r.size() > x + y) r.pop_back();
    vector<ll> vec;
    for (ll& e : p) vec.push_back(e);
    for (ll& e : q) vec.push_back(e);
    for (ll& e : r) vec.push_back(e);
    sort(vec.rbegin(), vec.rend());
    ll ans = 0;
    for (int i = 0; i < x + y; i++)
        ans += vec[i];
    cout << ans << endl;
}