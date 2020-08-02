void generate(vector<int>& A, vector<vector<int>>& ans, vector<int> t, int i, int sum) {
    if (sum == 0) { ans.push_back(t); return; }
    if (i == A.size()) return;
    int e = A[i++];
    do {
        generate(A, ans, t, i, sum);
        sum -= e, t.push_back(e);
    } while (sum >= 0);
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    int k = unique(A.begin(), A.end()) - A.begin();
    A.resize(k);
    vector<vector<int>> ans;
    generate(A, ans, vector<int>(), 0, B);
    sort(ans.begin(), ans.end());
    return ans;
}
