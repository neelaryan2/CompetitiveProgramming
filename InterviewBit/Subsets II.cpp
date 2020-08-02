using pii = pair<int, int>;
void generate(vector<pii>& A, vector<vector<int>>& ans, vector<int> t, int i) {
    if (i == A.size()) { ans.push_back(t); return; }
    pii p = A[i++];
    for (int j = 0; j <= p.second; j++) {
        generate(A, ans, t, i);
        t.push_back(p.first);
    }
}
vector<vector<int>> Solution::subsetsWithDup(vector<int> &A) {
    map<int, int> cnt;
    for (int e : A) cnt[e]++;
    vector<pii> v(cnt.begin(), cnt.end());
    vector<vector<int>> ans;
    generate(v, ans, vector<int>(), 0);
    sort(ans.begin(), ans.end());
    return ans;
}
