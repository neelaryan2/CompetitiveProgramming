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

void solve(int test) {
    int n;
    cin >> n;
    vector<vi> dist(n, vi(n));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            if (i == j)
                dist[i][j] = 0;
            else if (s[j] == '1')
                dist[i][j] = 1;
            else
                dist[i][j] = inf;
        }
    }
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    
    trace(dist);
    int m;
    cin >> m;
    vector<int> p(m);
    for (int& e : p) 
        cin >> e, e--;

    vector<int> ans(1, 0);
    for (int i = 1; i < m; i++) {
        int j = ans.back();
        if (dist[p[j]][p[i]] != i - j)
            ans.eb(i - 1);
    }
    ans.eb(m - 1);

    cout << ans.size() << '\n';
    for (int e : ans) 
        cout << p[e] + 1 << ' ';
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
