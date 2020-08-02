using pii = pair<int, int>;
#define x first
#define y second
bool solve(vector<vector<char>>& A, vector<pii> to, int& n, int& m) {
    if (to.empty()) return true;
    pii p = to.back(); to.pop_back();
    int r = p.x, c = p.y;
    int br = r - r % m, bc = c - c % m;
    vector<bool> can(n, 1);
    for (int i = 0; i < n; i++) {
        int ir = i / m, ic = i % m;
        char ch = A[i][c];
        if (ch != '.') can[ch - '1'] = 0;
        ch = A[r][i];
        if (ch != '.') can[ch - '1'] = 0;
        ch = A[br + ir][bc + ic];
        if (ch != '.') can[ch - '1'] = 0;
    }
    for (int i = 0; i < n; i++) {
        if (!can[i]) continue;
        A[r][c] = i + '1';
        bool ret = solve(A, to, n, m);
        if (ret) return true;
        A[r][c] = '.';
    }
    return false;
}
void Solution::solveSudoku(vector<vector<char>> &A) {
    int n = A.size(), m = sqrtl(n);
    vector<pii> to;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (A[i][j] == '.')
                to.emplace_back(i, j);
    bool valid = solve(A, to, n, m); 
    assert(valid);
}
