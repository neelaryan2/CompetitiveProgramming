using pii = pair<int, int>;
void generate(vector<pii>& A, vector<vector<int>>& ans, vector<int> t, int i, int sum) {
    if (sum == 0) { ans.push_back(t); return; }
    if (i == A.size()) return;
    pii p = A[i++];
    for (int j = 0; j <= p.second; j++) {
        generate(A, ans, t, i, sum);
        sum -= p.first, t.push_back(p.first);
        if (sum < 0) break;
    }
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    map<int, int> cnt;
    for (int e : A) cnt[e]++;
    vector<pii> v(cnt.begin(), cnt.end());
    vector<vector<int>> ans;
    generate(v, ans, vector<int>(), 0, B);
    sort(ans.begin(), ans.end());
    return ans;
}
