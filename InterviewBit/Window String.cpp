string Solution::minWindow(string A, string B) {
    char mn = A[0], mx = A[0];
    for (char c : A) {
        mn = min(mn, c);
        mx = max(mx, c);
    }
    for (char c : B) {
        mn = min(mn, c);
        mx = max(mx, c);
    }
    int num = mx - mn + 1, n = A.size();
    vector<int> cnt(num, 0);
    for (char c : B) cnt[c - mn]++;
    vector<vector<int>> v(num);
    int len = n + 1, ind = -1;
    for (int i = 0; i < n; i++) {
        v[A[i] - mn].push_back(i);
        bool bad = false;
        int mnm = i + 1;
        for (int j = 0; j < num; j++) {
            if (cnt[j] == 0) continue;
            int k = v[j].size();
            if (k < cnt[j]) {
                bad = true;
                break;
            }
            mnm = min(mnm, v[j][k - cnt[j]]);
        }
        if (bad) continue;
        int l = i - mnm + 1;
        if (l < len) {
            len = l;
            ind = mnm;
        }
    }
    if (ind == -1) ind = len = 0;
    return A.substr(ind, len);
}
