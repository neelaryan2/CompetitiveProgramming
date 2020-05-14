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
    vector<int> a(n);
    for (int& e : a) cin >> e;
    int mn = 1e9, mx = -1;
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] - a[i - 1] > 2) {
            mn = min(mn, cnt);
            mx = max(mx, cnt);
            cnt = 1;
        } else
            cnt++;
    }
    mn = min(mn, cnt);
    mx = max(mx, cnt);
    cout << mn << ' ' << mx << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
