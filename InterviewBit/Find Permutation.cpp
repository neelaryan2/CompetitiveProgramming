vector<int> Solution::findPerm(const string s, int n) {
    int num = n, last = 0;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        if (i == n - 1 || s[i] == 'D') {
            for (int j = i; j >= last; j--)
                ans[j] = num--;
            last = i + 1;
        }
    }
    return ans;
}
