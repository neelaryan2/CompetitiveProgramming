vector<vector<int> > Solution::solve(int n) {
    vector<vector<int>> ans(n, {1});
    for (int i = 1; i < n; i++) {
        ans[i].resize(i + 1, 1);
        for (int j = 1; j < i; j++)
            ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
    }
    return ans;
}
