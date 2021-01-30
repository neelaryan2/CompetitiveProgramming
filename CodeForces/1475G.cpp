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
const int N = 2e5 + 5;

vector<vi> divs(N);
void solve(int test) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& e : a)
        cin >> e;
    sort(all(a));
    vector<int> dp(n, 1), maxdp(N, 0);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        for (int j : divs[a[i]])
            dp[i] = max(dp[i], maxdp[j] + 1);
        maxdp[a[i]] = dp[i];
        mx = max(mx, dp[i]);
    }
    trace(a, dp);
    cout << (n - mx);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int j = 1; j < N; j++) {
        for (int i = 1; i * i <= j; i++) {
            if (j % i) continue;
            divs[j].eb(i);
            if (i * i != j)
                divs[j].eb(j / i);
        }
    }
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve(i);
        cout << '\n';
    }
}
