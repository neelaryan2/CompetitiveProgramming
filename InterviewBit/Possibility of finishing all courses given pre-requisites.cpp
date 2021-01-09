int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    int m = B.size(), n = A;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u = B[i], v = C[i];
        u--, v--;
        adj[u].push_back(v);
    }
    bool bad = false;
    vector<int> col(n, 0);
    function<void(int)> dfs = [&](int v) {
        col[v] = 1;
        for (int u : adj[v]) {
            if (col[u]) {
                if (col[u] == 1) bad = true;
            } else dfs(u);
        }
        col[v] = 2;
    };
    for (int i = 0; i < n; i++)
        if (!col[i]) dfs(i);
    return !bad;
}
