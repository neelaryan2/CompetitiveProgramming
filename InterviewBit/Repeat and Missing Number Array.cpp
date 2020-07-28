vector<int> Solution::repeatedNumber(const vector<int> &a) {
    int n = a.size();
    vector<int> cnt(n + 1, 0);
    for (int e : a) cnt[e]++;
    int A = -1, B = -1;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == 0) B = i;
        if (cnt[i] == 2) A = i;
    }
    return {A, B};
}
