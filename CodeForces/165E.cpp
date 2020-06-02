/* Author - Neel Aryan (@neelaryan2) */
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
const int N = 1 << 22;
int dp[N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fill(dp, dp + N, -1);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& e : a) {
        cin >> e;
        dp[e] = e;
        e ^= N - 1;
    }
    for (int i = 0; i < N; i++)
        for (int j = 1; j < N; j <<= 1)
            if ((i & j) && dp[i] == -1)
                dp[i] = dp[i ^ j];
    for (int& e : a)
        cout << dp[e] << ' ';
    cout << '\n';
}
