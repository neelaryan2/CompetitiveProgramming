void Solution::setZeroes(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size();
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < m; j++)
            if (A[i][j] == 0) found = true;
        if (!found) continue;
        for (int j = 0; j < m; j++)
            A[i][j]--;
    }
    for (int j = 0; j < m; j++) {
        bool found = false;
        for (int i = 0; i < n; i++)
            if (A[i][j] == -1) found = true;
        if (!found) continue;
        for (int i = 0; i < n; i++)
            A[i][j] = 0;
    }
}
