#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ppi = pair<int, pii>;
using vi = vector<int>;
using vpi = vector<pii>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, a, b;
    cin >> n >> a >> b;
    n *= 6;
    if (a * b >= n) {
        cout << a * b << '\n';
        cout << a << ' ' << b << '\n';
        return 0;
    }
    ll up = sqrtl(n), j;
    if (up * up < n) up++;
    ll na, nb, mn = 2e18;
    for (ll i = a; i <= up; i++) {
        j = 1 + (n - 1) / i;
        if (i * j >= n && j >= b && mn > i * j) {
            mn = i * j;
            na = i, nb = j;
        }
    }
    for (ll i = b; i <= up; i++) {
        j = 1 + (n - 1) / i;
        if (i * j >= n && j >= a && mn > i * j) {
            mn = i * j;
            na = j, nb = i;
        }
    }
    cout << mn << '\n';
    cout << na << ' ' << nb << '\n';
}