vector<int> Solution::flip(string A) {
    int n = A.size() + 1;
    vector<int> p(n, 0);
    for (int i = 0; i < n - 1; i++)        
        p[i + 1] = p[i] + (A[i] == '1');
    int sum = p[n - 1];
    for (int i = 0; i < n; i++)
        p[i] = 2 * p[i] - i;
    int mx = 0, val = -1;
    pair<int, int> ans = {n + 1, -1};
    for (int i = 1; i < n; i++) {
        int c = p[mx] - p[i];
        pair<int, int> cur = {mx + 1, i};
        if (p[i] > p[mx]) mx = i;
        if (c > val) {
            val = c;
            ans = cur;
        }
    }
    if (ans.second == -1) return {};
    vector<int> ret(2);
    ret[0] = ans.first;
    ret[1] = ans.second;
    return ret;
}
