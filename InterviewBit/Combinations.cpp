vector<vector<int> > Solution::combine(int n, int k) {
    vector<vector<int>> ans;
    for (int i = 0, sz = -1; i < (1 << n); i++) {
        int c = __builtin_popcount(i);
        if (c != k) continue;
        ans.emplace_back(), sz++;
        for (int b = 0; b < n; b++) 
            if ((i >> b) & 1)
                ans[sz].push_back(b + 1);
    }
    sort(ans.begin(), ans.end());
    return ans;
}
