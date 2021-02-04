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
#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

const int inf = 1e9 + 7;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
void solve(int test) {
    int n, m, r, c, x, y;
    cin >> n >> m >> r >> c >> x >> y;
    r--, c--;
    vector<string> g(n);
    vector<vi> d(n, vi(m, inf));
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }

    deque<pii> q;
    q.push_back(mp(r, c));
    d[r][c] = 0;

    while (!q.empty()) {
        pii v = q.front();
        q.pop_front();
        for (int i = 0; i < 4; i++) {
            auto u = v;
            u.x += dx[i], u.y += dy[i];
            if (u.x < 0 || u.x >= n) continue;
            if (u.y < 0 || u.y >= m) continue;
            if (g[u.x][u.y] == '*') continue;
            int w = (dy[i] == -1);
            if (d[u.x][u.y] > d[v.x][v.y] + w) {
                d[u.x][u.y] = d[v.x][v.y] + w;
                if (w == 1)
                    q.push_back(u);
                else
                    q.push_front(u);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int l = d[i][j];
            int r = l + j - c;
            if (l <= x && r <= y) ans++;
        }
    }
    cout << ans;
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
