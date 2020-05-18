class Solution {
   public:
    void dfs(int i, int j, vector<vector<char>>& g) {
        g[i][j] = '0';
        int n = g.size(), m = g[0].size();
        if (i < n - 1 && g[i + 1][j] != '0') dfs(i + 1, j, g);
        if (j < m - 1 && g[i][j + 1] != '0') dfs(i, j + 1, g);
        if (i > 0 && g[i - 1][j] != '0') dfs(i - 1, j, g);
        if (j > 0 && g[i][j - 1] != '0') dfs(i, j - 1, g);
    }
    int numIslands(vector<vector<char>>& g) {
        if (g.empty() || g[0].empty()) return 0;
        int n = g.size(), m = g[0].size(), ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == '0') continue;
                dfs(i, j, g);
                ans++;
            }
        }
        return ans;
    }
};