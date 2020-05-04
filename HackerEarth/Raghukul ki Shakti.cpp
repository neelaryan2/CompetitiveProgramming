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
const int inf = 1e9;
const int N = 1e6 + 10;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> cnt(N, 0), dp(N, 0);
    vector<int> arr(n), ans(n);
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        cnt[e]++;
        arr[i] = e;
    }
    for (int i = 1; i < N; i++) {
        if (cnt[i] == 0 || dp[i] < 0) continue;
        for (int j = 2 * i; j < N; j += i) {
            if (cnt[j] == 0) continue;
            dp[i] += cnt[j];
            dp[j] -= cnt[i];
        }
    }
    for (int i = 0; i < n; i++) {
        ans[i] = dp[arr[i]];
        cout << ans[i] << ' ';
    }
    cout << '\n';
}