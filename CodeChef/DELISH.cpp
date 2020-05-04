#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()

void solve() {
    int n;
    cin >> n;
    vector<ll> arr(n), leftmx(n), leftmn(n), rightmn(n), rightmx(n);
    for (ll& e : arr) cin >> e;
    leftmx[0] = arr[0];
    leftmn[0] = arr[0];
    for (int i = 1; i < n; i++) {
        leftmx[i] = max(leftmx[i - 1], 0LL) + arr[i];
        leftmn[i] = min(leftmn[i - 1], 0LL) + arr[i];
    }
    rightmx[n - 1] = arr[n - 1];
    rightmn[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        rightmx[i] = max(rightmx[i + 1], 0LL) + arr[i];
        rightmn[i] = min(rightmn[i + 1], 0LL) + arr[i];
    }
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        ans = max(ans, abs(leftmx[i - 1] - rightmn[i]));
        ans = max(ans, abs(leftmn[i - 1] - rightmx[i]));
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
