/* Author - Neel Aryan (@neelaryan2) */
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<vi> d(n);
    for (int i = 0; i < n; i++) {
        d[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> d[i][j];
        }
    }
    vector<int> x(n);
    vector<ll> ans(n, 0);
    vector<bool> vis(n, false);
    for (int& e : x) cin >> e, e--;
    for (int t = n - 1; t >= 0; t--) {
        int v = x[t];
        vis[v] = true;
        ll& cur = ans[t];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                d[i][j] = min(d[i][j], d[i][v] + d[v][j]);
                if (vis[i] && vis[j]) cur += d[i][j];
            }
        }
    }
    for (ll& i : ans) cout << i << ' ';
    cout << '\n';
}
