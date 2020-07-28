bool check(string s) {
    vector<int> cnt(10, 0);
    for (char c : s)
        if (c != '.')
            cnt[c - '1']++;
    for (int i = 0; i < 10; i++)
        if (cnt[i] > 1) return false;
    return true;
}
int Solution::isValidSudoku(const vector<string> &A) {
    int n = A.size(), m = sqrtl(n);
    for (int i = 0; i < n; i++) {
        if (!check(A[i])) return 0;
        string s;
        for (int j = 0; j < n; j++)
            s += A[j][i];
        if (!check(s)) return 0;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            string st;
            for (int r = 0; r < m; r++)
                for (int s = 0; s < m; s++)
                    st += A[m * i + r][m * j + s];
            if (!check(st)) return 0;
        }
    }
    return 1;
}
