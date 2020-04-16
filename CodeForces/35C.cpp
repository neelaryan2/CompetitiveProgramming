#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define mp make_pair
#define fi first
#define se second
const int inf = 1e9;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	int dist[n][m];
	bool vis[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			vis[i][j] = false;
			dist[i][j] = inf;
		}
	}
	queue<pii> q;
	for (int i = 0; i < k; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		q.push(mp(u, v));
		dist[u][v] = 0;
		vis[u][v] = true;
	}
	int mx = -1;
	pii ans;
	while (!q.empty()) {
		pii p = q.front(); q.pop();
		int u = p.fi, v = p.se;
		for (int i = -1; i < 2; i++) {
			for (int j = -1; j < 2; j++) {
				if (i * j) continue;
				if (i == 0 && j == 0) continue;
				int x = u + i, y = v + j;
				if (x >= n || x < 0) continue;
				if (y >= m || y < 0) continue;
				dist[x][y] = min(dist[x][y], dist[u][v] + 1);
				if (dist[x][y] > mx) {
					mx = dist[x][y];
					ans = mp(x, y);
				}
				if (vis[x][y]) continue;
				vis[x][y] = true;
				q.push(mp(x, y));
			}
		}
	}
	cout << 1 + ans.fi << " " << 1 + ans.se << endl;
}