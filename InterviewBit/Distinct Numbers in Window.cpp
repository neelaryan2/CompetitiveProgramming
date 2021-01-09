vector<int> Solution::dNums(vector<int> &A, int B) {
    int n = A.size();
    if (B > n) return {};
    map<int, int> cnt;
    set<int> w;
    for (int i = 0; i < B; i++) {
        w.insert(A[i]);
        cnt[A[i]]++;
    }
    vector<int> ans(1, w.size());
    for (int i = B; i < n; i++) {
        w.insert(A[i]);
        cnt[A[i]]++;
        if (--cnt[A[i - B]] == 0)
            w.erase(A[i - B]);
        ans.push_back(w.size());
    }
    return ans;
}
