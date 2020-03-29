#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using piii = pair<pii, int>;
using vs = vector<string>;
#define fi first
#define se second
const ll mod = 998244353;

vector<unordered_set<int>> nadj;
vector<vector<int>> components;
set<int> unvis;

void bfs(int s) {
	components.emplace_back();
	queue<int> q; q.push(s);
	unvis.erase(unvis.find(s));
	while (!q.empty()) {
		int v = q.front(); q.pop();
		components.back().emplace_back(v);
		for (auto it = unvis.begin(); it != unvis.end();) {
			if (nadj[v].find(*it) != nadj[v].end()) it++;
			else q.push(*it), it = unvis.erase(it);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	nadj.resize(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		nadj[u].insert(v);
		nadj[v].insert(u);
	}
	for (int i = 0; i < n; i++)
		unvis.insert(i);
	for (int i = 0; i < n; i++) {
		if (unvis.find(i) != unvis.end())
			bfs(i);
	}
	cout << components.size() << endl;
	for (auto& s : components) {
		cout << s.size();
		for (int& j : s)
			cout << " " << j + 1;
		cout << endl;
	}
}