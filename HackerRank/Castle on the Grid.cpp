#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pi pair<int,int>
#define fi first
#define se second

int inf = 1e9, n;
vector<vector<bool>> grid, remain;
inline bool chk(int x, int y) {
    return (x < n) && (x >= 0) &&
           (y < n) && (y >= 0) &&
           remain[x][y];
}
int minimumMoves(int startX, int startY, int goalX, int goalY) {
    vector<vi> dist(n, vi(n, inf));
    queue<pi> q;
    q.push({startX, startY});
    dist[startX][startY] = 0;
    while (!q.empty()) {
        int x = q.front().fi, y = q.front().se;
        remain[x][y] = false; q.pop();
        for (int l = -1; l < 2; l++) {
            for (int m = -1; m < 2; m++) {
                if (l * m || l == m) continue;
                int i = x + l, j = y + m;
                while (chk(i, j)) {
                    dist[i][j] = min(dist[i][j], 1 + dist[x][y]);
                    q.push({i, j}); i += l; j += m;
                }
            }
        }
    }
    return dist[goalX][goalY];
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n;
    grid.resize(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            char c; cin >> c;
            grid[i].emplace_back(c == '.');
        }
    remain = grid;
    int startX, startY, goalX, goalY;
    cin >> startX >> startY >> goalX >> goalY;
    int result = minimumMoves(startX, startY, goalX, goalY);
    cout << result << "\n";
    return 0;
}
