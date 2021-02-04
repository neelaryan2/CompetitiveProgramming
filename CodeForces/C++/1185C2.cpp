#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

const int inf = 1e9 + 7;
const int T = 101;

void solve(int test) {
    int n, M, ans;
    cin >> n >> M;
    vector<int> cnt(T, 0);
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        int sum = t, taken = 0;
        for (int j = 1; j < T; j++) {
            int cur = min(cnt[j], (M - sum) / j);
            sum += j * cur;
            taken += cur;
        }
        cnt[t]++;
        ans = i - taken;
        cout << ans << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve(i);
        cout << '\n';
    }
}
