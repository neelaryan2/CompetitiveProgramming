const vector<int> dx = {-1, 0, 0, 1};
const vector<int> dy = {0, -1, 1, 0};
void Solution::solve(vector<vector<char> > &A) {
    int n = A.size(), m = A[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    function<void(int, int, bool)> dfs = [&](int x, int y, bool b) {
        vis[x][y] = true;
        if (b) A[x][y] = 'X';
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx < 0 || xx >= n) continue;
            if (yy < 0 || yy >= m) continue;
            if (A[xx][yy] == 'X') continue;
            if (!vis[xx][yy]) dfs(xx, yy, b);
        }
    };
    for (int i = 0; i < n; i++) {
        for (int j : {0, m - 1}) {
            if (A[i][j] == 'X' || vis[i][j]) continue;
            dfs(i, j, false);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j : {0, n - 1}) {
            if (A[j][i] == 'X' || vis[j][i]) continue;
            dfs(j, i, false);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == 'X' || vis[i][j]) continue;
            dfs(i, j, true);
        }
    }
}
