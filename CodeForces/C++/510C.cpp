#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int alph = 26;
bool cyc = false;

vector<vector<int>> adj(alph);
vector<int> vis(alph, 0);
stack<char> st;

bool add(string& s1, string& s2) {
	int l = min(s1.size(), s2.size());
	int ind = -1;
	for (int i = 0; i < l; i++) {
		if (s1[i] == s2[i]) continue;
		ind = i; break;
	}
	if (ind == -1) return (l == s1.size());
	adj[s1[ind] - 'a'].emplace_back(s2[ind] - 'a');
	return true;
}
void dfs(int v) {
	vis[v] = 1;
	for (int u : adj[v]) {
		if (vis[u] == 2) continue;
		if (vis[u] == 1) cyc = true;
		if (vis[u] == 0) dfs(u);
	}
	st.push(v + 'a');
	vis[v] = 2;
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	vector<string> vec(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i];
	bool flag = false;
	for (int i = 0; i < n - 1; i++) {
		if (!add(vec[i], vec[i + 1]))
			flag = true;
	}
	if (flag) {
		cout << "Impossible" << endl;
		return 0;
	}
	for (int i = 0; i < alph; i++)
		if (vis[i] == 0) dfs(i);
	if (cyc) {
		cout << "Impossible" << endl;
		return 0;
	}
	while (!st.empty()) {
		char c = st.top();
		st.pop(); cout << c;
	}
	cout << endl;
}