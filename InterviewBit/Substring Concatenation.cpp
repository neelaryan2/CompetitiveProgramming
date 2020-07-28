vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    map<string, int> id, cnt;
    for (string s : B) cnt[s]++;
    int index = 0;
    for (auto s : cnt) id[s.first] = index++;
    int n = A.size(), m = B.size(), l = B[0].size();
    multiset<int> orig, s;
    for (string t : B) orig.insert(id[t]);
    auto get = [&](int i) {
        auto it = id.find(A.substr(i, l));
        if (it == id.end()) return -1;
        return it->second;
    };
    int k = m * l;
    vector<int> ans;
    for (int j = 0; j + k <= n; j++){
        s.clear();
        for (int i = j; i < j + k; i += l)
            s.insert(get(i));
        if (s.size() < m) break;
        if (s == orig) 
            ans.push_back(j);
    }
    return ans;
}
