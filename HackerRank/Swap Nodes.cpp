#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> depth;
vector<int> l, r;
void dfs(int v, int d = 1) {
	depth[d].emplace_back(v);
	if (l[v] >= 0) dfs(l[v], d + 1);
	if (r[v] >= 0) dfs(r[v], d + 1);
}
void inorder(int v) {
	if (l[v] >= 0) inorder(l[v]);
	cout << v + 1 << " ";
	if (r[v] >= 0) inorder(r[v]);
}
int main() {
	int n, root = 0; cin >> n;
	l.resize(n); r.resize(n);
	depth.resize(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> l[i] >> r[i];
		l[i]--; r[i]--;
	}
	dfs(root);
	while (depth.back().empty())
		depth.pop_back();
	int h = depth.size();
	int t, k; cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> k;
		for (int j = k; j < h; j += k)
			for (int v : depth[j])
				swap(l[v], r[v]);
		inorder(root);
		cout << "\n";
	}
}
