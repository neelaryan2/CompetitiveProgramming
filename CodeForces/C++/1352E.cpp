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
    vector<ll> p(n + 1, 0);
    vector<int> cnt(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int e;
        cin >> e;
        cnt[e]++;
        p[i] = p[i - 1] + e;
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = i + 2; j <= n; j++) {
            ll sum = p[j] - p[i];
            if (sum > n) break;
            if (cnt[sum] > 0) {
                ans += cnt[sum];
                cnt[sum] = 0;
            }
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
