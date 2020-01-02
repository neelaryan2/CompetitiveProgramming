#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, goal;
vector<ll> m;
bool possible(ll k) {
    ll sum = 0;
    for (ll c : m)
        if (sum < goal) sum += k / c;
        else return true;
    return sum >= goal;
}
int main() {
    cin >> n >> goal; m.resize(n);
    for (int i = 0; i < n; i++)
        cin >> m[i];
    ll lo = 0, hi = 1e18, mid;
    while (lo < hi - 1) {
        mid = lo + (hi - lo) / 2;
        if (possible(mid)) hi = mid;
        else lo = mid;
    }
    cout << hi << endl;
}
