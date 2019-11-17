#include <bits/stdc++.h>
using namespace std;
#define si set<int>
#define pp pair<int, int>
#define ll long long
#define mp make_pair
vector<si> adj;
vector<si> rev_adj;
vector<int> out;
set<pp>s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	adj.resize(n);
	rev_adj.resize(n);
	int x, y;

	for (int i = 0; i < n; i++)
		out.push_back(0);

	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		rev_adj[y].insert(x);
		adj[x].insert(y);
		out[x]++;
	}

	for (int i = 0; i < n; i++)
		s.insert(mp(out[i], i));

	ll ans = 0;
	while (true) {
		if ((*s.begin()).first > 1) break;
		if (s.size() == 0) break;

		int deg = (*s.begin()).first;
		int node = (*s.begin()).second;

		if (deg == 0) {
			vector<int> v;
			for (auto it = rev_adj[node].begin(); it != rev_adj[node].end(); it++)
				v.push_back(*it);
			for (int u : v) {
				rev_adj[node].erase(u);
				adj[u].erase(node);
				ans++;
				s.erase(mp(out[u], u));
				out[u]--;
				s.insert(mp(out[u], u));
			}
			s.erase(mp(out[node], node));
		}
		else if (deg == 1) {
			int id = (*(adj[node].begin()));
			if (adj[id].find(node) != adj[id].end()) {
				ans++;
				rev_adj[node].erase(id);
				adj[id].erase(node);
				s.erase(mp(out[id], id));
				out[id]--;
				s.insert(mp(out[id], id));
			}
			s.erase(mp(out[node], node));
		}
	}
	cout << ans << endl;
}