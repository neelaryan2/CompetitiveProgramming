class Solution {
   public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if (numRows == 0) return ans;
        ans.assign(numRows, vector<int>(1, 1));
        for (int i = 1; i < numRows; i++) {
            ans[i].assign(i + 1, 1);
            for (int j = 1; j < i; j++) {
                ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1];
            }
        }
        return ans;
    }
};