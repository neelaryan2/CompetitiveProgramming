#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> grid;
inline bool check(int x, int y) {
    return (x < n) && (x >= 0) &&
           (y < m) && (y >= 0) &&
           grid[x][y];
}
int dfs(int x, int y) {
    int ans = 1;
    grid[x][y] = 0;
    for (int i = -1; i < 2; i++)
        for (int j = -1; j < 2; j++)
            if (check(x + i, y + j))
                ans += dfs(x + i, y + j);
    return ans;
}
int maxRegion() {
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j])
                ans = max(ans, dfs(i, j));
    return ans;
}
int main() {
    cin >> n >> m;
    grid.resize(n);
    for (int i = 0; i < n; i++) {
        grid[i].resize(m);
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    }
    cout << maxRegion() << "\n";
    return 0;
}
