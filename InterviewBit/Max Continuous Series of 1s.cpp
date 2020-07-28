vector<int> Solution::maxone(vector<int> &a, int m) {
    int n = a.size();
    int L = -1, R = -1, ans = -1;
    for (int r = 0, l = 0, cnt = 0; r < n; r++) {
        cnt += (a[r] == 0);
        while (l <= r && cnt > m)
            cnt -= (a[l++] == 0);
        int cur = r - l + 1;
        if (ans < cur) {
            ans = cur;
            L = l, R = r;
        }
    }
    vector<int> res;
    for (int i = L; i <= R; i++)
        res.push_back(i);
    return res;
}
