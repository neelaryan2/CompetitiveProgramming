int dp[51][51][51];
bool check(const string& A, const string& B, int i1, int i2, int l) {
    string a = A.substr(i1, l), b = B.substr(i2, l);
    sort(a.begin(), a.end()); sort(b.begin(), b.end());
    if (a != b) return false;
    if (l == 1) return true;
    if (dp[i1][i2][l] != -1) return dp[i1][i2][l];
    bool res = 0;
    for (int i = 1; i < l; i++) {
        res |= check(A, B, i1, i2, i) && check(A, B, i1 + i, i2 + i, l - i);
        res |= check(A, B, i1, i2 + l - i, i) && check(A, B, i1 + i, i2, l - i);
    }
    return dp[i1][i2][l] = res;    
}
int Solution::isScramble(const string A, const string B) {
    int n = A.size(), m = B.size();
    if (m != n) return false;
    memset(dp, -1, sizeof dp);
    bool ans = check(A, B, 0, 0, n);
    return ans;
}
