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
int N = 1e5 + 5;
vector<int> cnt(N, 0);
vector<ll> dp(N, 0);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& e : a) {
        cin >> e;
        cnt[e]++;
    }
    dp[1] = cnt[1];
    for (int i = 2; i < N; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + 1LL * i * cnt[i]);
    cout << dp.back() << '\n';
}
