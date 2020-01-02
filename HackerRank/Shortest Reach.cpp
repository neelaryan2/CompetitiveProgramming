#include<bits/stdc++.h>
using namespace std;

class Graph {
    const int w = 6;
    const int inf = 2e9;
    int n;
    vector<vector<int>> adj;
public:
    Graph(int _n) {
        n = _n;
        adj.resize(n);
    }
    void add_edge(int u, int v) {
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    vector<int> shortest_reach(int start) {
        vector<int> dist(n, inf);
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(start);
        dist[start] = 0;
        vis[start] = true;
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int u : adj[v]) {
                if (vis[u]) continue;
                dist[u] = dist[v] + w;
                q.push(u); vis[u] = true;
            }
        }
        for (int& d : dist)
            if (d == inf) d = -1;
        return dist;
    }
};

int main() {
    int queries;
    cin >> queries;
    for (int t = 0; t < queries; t++) {
        int n, m;
        cin >> n >> m;
        Graph graph(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            graph.add_edge(u, v);
        }
        int startId;
        cin >> startId;
        startId--;
        vector<int> distances = graph.shortest_reach(startId);
        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}