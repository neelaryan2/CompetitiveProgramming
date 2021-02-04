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
set<int> unvis;

void bfs(int s) {
	queue<int> q; q.push(s);
	unvis.erase(unvis.find(s));
	while (!q.empty()) {
		int v = q.front(); q.pop();
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
	int n, m, k;
	cin >> n >> m >> k;
	nadj.resize(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		nadj[u].insert(v);
		nadj[v].insert(u);
	}
	if (n - 1 - nadj[0].size() < k) {
		puts("impossible");
		return 0;
	}
	for (int i = 0; i < n; i++)
		unvis.insert(i);
	int cnt1 = 0;
	for (int i = 0; i < n; i++) {
		if (unvis.find(i) != unvis.end())
			bfs(i), cnt1++;
	}
	for (int i = 0; i < n; i++) {
		if (i != 0) nadj[i].insert(0);
		if (i != 0) nadj[0].insert(i);
		unvis.insert(i);
	}
	int cnt2 = 0;
	for (int i = 0; i < n; i++) {
		if (unvis.find(i) != unvis.end())
			bfs(i), cnt2++;
	}
	puts((cnt1 == 1 && cnt2 - 1 <= k) ? "possible" : "impossible");
}