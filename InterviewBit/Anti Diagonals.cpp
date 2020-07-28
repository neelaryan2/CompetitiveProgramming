vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int n = A.size();
    vector<vector<int>> ans(2 * n - 1);
    for (int i = 0; i < n; i++)
        for (int j = n - 1; j >= 0; j--)
            ans[i + j].push_back(A[i][j]);
    return ans;
}
