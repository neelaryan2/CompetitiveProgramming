#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using vs = vector<string>;
#define fi first
#define se second
const ll inf = 1e18;

vs split(const string& str, const string& delim) {
	vs tokens;
	int prev = 0, pos = 0, n = str.size();
	while (pos < n && prev < n) {
		pos = str.find(delim, prev);
		if (pos == string::npos) pos = n;
		string token = str.substr(prev, pos - prev);
		if (!token.empty()) tokens.push_back(token);
		prev = pos + delim.size();
	}
	return tokens;
}
string strip(const string& str) {
	int s = 0, e = str.size() - 1;
	while (isspace(str[s])) s++;
	while (isspace(str[e])) e--;
	return str.substr(s, e - s + 1);
}

vs nodes;
vector<vector<int>> ans;
int I = 0;
void dfs(int d) {
	int sz = stoi(nodes[2 * I + 1]);
	int curr = I++;
	if (d + 1 > ans.size()) ans.emplace_back();
	ans[d].emplace_back(curr);
	if (sz == 0) return;
	for (int i = 0; i < sz; i++)
		dfs(d + 1);
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	string s; cin >> s;
	nodes = split(strip(s), ",");
	while (I < nodes.size() / 2) dfs(0);
	cout << ans.size() << endl;
	for (auto v : ans) {
		for (int i : v)
			cout << nodes[2 * i] << " ";
		cout << endl;
	}
}