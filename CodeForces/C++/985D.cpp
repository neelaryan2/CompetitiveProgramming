#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
ll cel(ll n, ll k) {
    if (n == 0) return 0;
    return 1 + (n - 1) / k;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, h, k;
    cin >> n >> h;
    ll res = n + (h * (h - 1)) / 2;
    res = sqrtl(res), k = res;
    if (res < h) {
        ld tmp = sqrtl(1 + 8 * n);
        tmp = (tmp - 1) / 2;
        ll cur = tmp;
        ll val = (cur * (cur + 1)) / 2;
        cur += cel(n - val, cur);
        cout << cur << endl;
        return 0;
    }
    res = n - res * res + (h * (h - 1)) / 2;
    res = cel(res, k);
    cout << (2 * k - h + res) << endl;
}
