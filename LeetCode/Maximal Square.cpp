class Solution {
   public:
    int maximalSquare(vector<vector<char>>& mat) {
        int n = mat.size();
        if (n == 0) return 0;
        int m = mat[0].size();
        if (m == 0) return 0;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                matrix[i][j] = (mat[i][j] == '1');
        for (int i = 1; i < n; i++)
            matrix[i][0] += matrix[i - 1][0];
        for (int j = 1; j < m; j++)
            matrix[0][j] += matrix[0][j - 1];
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                matrix[i][j] += matrix[i - 1][j] + matrix[i][j - 1] - matrix[i - 1][j - 1];
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k <= min(i, j); k++) {
                    int curr = matrix[i][j];
                    if (i >= k + 1 && j >= k + 1) curr += matrix[i - k - 1][j - k - 1];
                    if (i >= k + 1) curr -= matrix[i - k - 1][j];
                    if (j >= k + 1) curr -= matrix[i][j - k - 1];
                    if (curr == (k + 1) * (k + 1)) {
                        ans = max(curr, ans);
                    }
                }
            }
        }
        return ans;
    }
};