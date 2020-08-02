vector<vector<int> > Solution::subsets(vector<int> &A) {
    int n = A.size();
    vector<vector<int>> ans(1 << n);
    for (int i = 0; i < (1 << n); i++){
        for (int b = 0; b < n; b++)
            if ((i >> b) & 1)
                ans[i].push_back(A[b]);
        sort(ans[i].begin(), ans[i].end());
    }
    sort(ans.begin(), ans.end());
    return ans;
}
