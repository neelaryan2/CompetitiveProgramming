int Solution::candy(vector<int> &A) {
    int n = A.size();
    vector<int> ans(n, 1);
    for (int i = 1; i < n; i++)
        if (A[i] > A[i - 1])
            ans[i] = max(ans[i], 1 + ans[i - 1]);
    int ret = ans.back();
    for (int i = n - 2; i >= 0; i--) {
        if (A[i] > A[i + 1])
            ans[i] = max(ans[i], 1 + ans[i + 1]);
        ret += ans[i];
    }
    return ret;
}
