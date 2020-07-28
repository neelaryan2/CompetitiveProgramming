vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    map<string, vector<int>> ids;
    int n = A.size();
    for (int i = 0; i < n; i++) {
        string s = A[i];
        sort(s.begin(), s.end());
        ids[s].push_back(i + 1);
    }
    vector<vector<int>> ans;
    for (auto p : ids) {
        ans.emplace_back();
        for (int i : p.second)
            ans.back().emplace_back(i);
    }
    return ans;
}
