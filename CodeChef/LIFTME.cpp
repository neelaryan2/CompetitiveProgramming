#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
void solve() {
    ll n, q, f, d;
    cin >> n >> q;
    ll curr = 0, ans = 0;
    for (int i = 0; i < q; i++) {
        cin >> f >> d;
        ans += abs(curr - f) + abs(f - d);
        curr = d;
    }
    cout << ans << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
}