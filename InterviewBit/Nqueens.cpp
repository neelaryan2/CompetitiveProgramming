void generate(vector<vector<string>>& ans, vector<int> occ, int n) {
    int k = occ.size();
    if (k == n) {
        ans.emplace_back();
        vector<string>& s = ans.back();
        s.resize(n);
        for (int i = 0; i < n; i++) {
            s[i].assign(n, '.');
            s[i][occ[i]] = 'Q';
        }
        return;
    }
    vector<bool> can(n, 1);
    for (int i = 0; i < k; i++) {
        int j = occ[i], c;
        c = j + k - i;
        if (c < n) can[c] = 0;
        c = j - k + i;
        if (c >= 0) can[c] = 0;
        can[j] = 0;
    }
    for (int j = 0; j < n; j++) {
        if (!can[j]) continue;
        occ.push_back(j);
        generate(ans, occ, n);
        occ.pop_back();
    }
}
vector<vector<string> > Solution::solveNQueens(int n) {
    vector<vector<string>> ans;
    generate(ans, vector<int>(), n);
    return ans;
}
