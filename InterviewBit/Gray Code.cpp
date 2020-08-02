vector<int> Solution::grayCode(int k) {
    int n = (1 << k);
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
        ans[i] = i ^ (i >> 1);
    return ans;
}
