#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
const int inf = 1e9;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    int nm = n * m;
    vector<bool> vis(nm);
    vi can[4];
    int mapp[] = {-1, 1, -m, m};
    // left, right, up, down
    for (int i = 0; i < 4; i++)
        can[i].assign(nm, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int v = i * m + j;
            char c;
            cin >> c;
            vis[v] = (c == '#');
            if (vis[v]) continue;
            if (i != 0) can[2][v] = min(k, can[2][v - m] + 1);
            if (j != 0) can[0][v] = min(k, can[0][v - 1] + 1);
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int v = i * m + j;
            if (vis[v]) continue;
            if (i != n - 1) can[3][v] = min(k, can[3][v + m] + 1);
            if (j != m - 1) can[1][v] = min(k, can[1][v + 1] + 1);
        }
    }
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--, y1--, x2--, y2--;
    int start = x1 * m + y1, ends = x2 * m + y2;
    vector<int> dist(nm, -1);
    queue<int> q;
    dist[start] = 0;
    vis[start] = true;
    q.push(start);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int j = 0; j < 4; j++) {
            int mul = mapp[j], lim = can[j][v];
            for (int i = 1; i <= lim; i++) {
                int to = v + i * mul;
                if (dist[to] == dist[v]) break;
                if (vis[to]) continue;
                dist[to] = dist[v] + 1;
                vis[to] = true;
                q.push(to);
            }
        }
    }
    cout << dist[ends] << endl;
}