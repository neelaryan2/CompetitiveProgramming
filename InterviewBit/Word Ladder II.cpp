const int inf = 1e9;
vector<vector<string> > Solution::findLadders(string A, string B, vector<string> &C) {
    set<string> s(C.begin(), C.end());
    s.insert(A); s.insert(B);
    C.assign(s.begin(), s.end());
    int n = C.size();
    vector<vector<int>> adj(n);
    map<string, int> ids;
    for (int i = 0; i < n; i++)
        ids[C[i]] = i;
    queue<int> q;
    vector<int> dist(n, inf);
    vector<vector<int>> par(n);
    int st = ids[A], en = ids[B];
    q.push(st); dist[st] = 1;
    par[st] = {-1};
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
                if (dist[u] < dist[v] + 1) continue;
                if (dist[u] > dist[v] + 1) {
                    q.push(u); dist[u] = dist[v] + 1;
                    par[u].assign(1, v);
                } else {
                    par[u].push_back(v);
                }
            }
            c[i] = ch;
        }
    }
    vector<vector<string>> ans;
    function<void(int, vector<int>&)> get = [&](int v, vector<int>& path) {
        if (v == -1) {
            int k = path.size();
            vector<string> res(k);
            for (int i = 0; i < k; i++)
                res[i] = C[path[k - 1 - i]];
            ans.push_back(res);
            return;
        }
        for (int p : par[v]) {
            path.push_back(v);
            get(p, path);
            path.pop_back();
        }  
    };
    vector<int> cur;
    get(en, cur);
    return ans;
    
}
