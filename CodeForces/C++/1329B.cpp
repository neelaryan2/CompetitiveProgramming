#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll d, m;
    cin >> d >> m;
    if (d == 1) return 1 % m;
    int b = log2(d);
    ll res = 1 % m, pw = 2, ans;
    for (ll i = 1; i <= b; i++, pw <<= 1) {
        if (i == b) pw = d - pw + 1;
        ans = (pw * res) % m;
        ans = (ans + pw + res) % m;
        res = ans;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) cout << solve() << '\n';
}