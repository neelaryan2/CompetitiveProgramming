const vector<int> dx = {-1, 0, 0, 1};
const vector<int> dy = {0, -1, 1, 0};
int Solution::exist(vector<string> &A, string B) {
    int n = A.size(), m = A[0].size();
    function<bool(int, int, int)> dfs = [&](int x, int y, int id) {
        if (id == B.size()) return true;
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx < 0 || xx >= n) continue;
            if (yy < 0 || yy >= m) continue;
            if (A[xx][yy] != B[id]) continue;
            if (dfs(xx, yy, id + 1)) return true;
        }
        return false;
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] != B[0]) continue;
            if (dfs(i, j, 1)) return 1;
        }
    }
    return 0;
}
