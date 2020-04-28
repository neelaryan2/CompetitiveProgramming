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
    vector<int> arr(n);
    for (int& e : arr) cin >> e;
    vector<pii> vec;
    for (int i = 0; i < n; i++) {
        int count = 1;
        while (i < n - 1 && arr[i] == arr[i + 1]) {
            count++;
            i++;
        }
        vec.pb({arr[i], count});
    }
    vector<int> cnt(1001, 0);
    for (pii p : vec) {
        cnt[p.fi] += p.se / 2;
        if (p.se & 1) cnt[p.fi]++;
    }
    int ans = 0, mx = -1;
    for (int i = 0; i < 1001; i++) {
        if (cnt[i] > mx) {
            mx = max(mx, cnt[i]);
            ans = i;
        }
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