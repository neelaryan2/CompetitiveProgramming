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
    int n, k;
    cin >> n >> k;
    vector<int> arr(n + 1, 0), a(n);
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        a[i] = e;
        arr[e] = 1;
    }
    int tot = 0;
    for (int i : arr) tot += i;
    if (tot > k) {
        cout << -1 << '\n';
        return;
    }
    if (tot < k) {
        for (int i = 1; i <= n; i++) {
            if (!arr[i]) {
                arr[i] = 1;
                tot++;
            }
            if (tot == k) break;
        }
    }
    cout << n * tot << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++)
            if (arr[j]) cout << j << " ";
    }
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
