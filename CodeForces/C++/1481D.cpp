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
    int n, m;
    cin >> n >> m;
    bool g[n][n];
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            g[i][j] = (s[j] == 'a');
        }
    }
    if ((m % 2 == 0) && (n == 2) && (g[0][1] != g[1][0])) {
        cout << "NO";
        return;
    }
    cout << "YES\n";
    if (m % 2) {
        for (int i = 0; i <= m; i++)
            cout << ((i % 2) + 1) << ' ';
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (g[i][j] == g[j][i]) {
                for (int t = 0; t <= m; t++)
                    cout << ((t % 2 ? i : j) + 1) << ' ';
                return;
            }
        }
    }
    int a = 0, b = 1, c = 2;
    while (g[a][b] != g[b][c]) {
        a = (a + 1) % 3;
        b = (b + 1) % 3;
        c = (c + 1) % 3;
    }
    if (m % 4 == 0) {
        cout << (b + 1) << ' ';
        for (int i = 0; i < m / 4; i++) {
            cout << (c + 1) << ' ' << (b + 1) << ' ';
            cout << (a + 1) << ' ' << (b + 1) << ' ';
        }
    } else {
        cout << (a + 1) << ' ';
        for (int i = 0; i < m / 4; i++) {
            cout << (b + 1) << ' ' << (c + 1) << ' ';
            cout << (b + 1) << ' ' << (a + 1) << ' ';
        }
        cout << (b + 1) << ' ' << (c + 1) << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve(i);
        cout << '\n';
    }
}
