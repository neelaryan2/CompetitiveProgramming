int Solution::solve(string A, string B, vector<string> &C) {
    set<string> s(C.begin(), C.end());
    s.insert(A); s.insert(B);
    C.assign(s.begin(), s.end());
    int n = C.size();
    vector<vector<int>> adj(n);
    map<string, int> ids;
    for (int i = 0; i < n; i++)
        ids[C[i]] = i;
    queue<int> q;
    vector<int> dist(n, -1);
    vector<bool> vis(n, false);
    int st = ids[A], en = ids[B];
    q.push(st); vis[st] = true; dist[st] = 1;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        string c = C[v];
        for (int i = 0; i < c.size(); i++) {
            char ch = C[v][i];
            for (int j = 0; j < 26; j++) {
                if (ch == char(j + 'a')) continue;
                c[i] = char(j + 'a');
                auto it = ids.find(c);
                if (it == ids.end()) continue;
                int u = it->second;
                if (vis[u]) continue;
                q.push(u); vis[u] = true; dist[u] = dist[v] + 1;
            }
            c[i] = ch;
        }
    }
    return dist[en];
}
