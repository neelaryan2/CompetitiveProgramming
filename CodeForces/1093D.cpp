#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mxn = 3e5 + 5;
const int kMod = 998244353;

struct ModInt {
	long long n;
	ModInt(long long n = 0) : n(n % kMod) {}
	ModInt operator+(const ModInt& oth) { return n + oth.n; }
	ModInt operator-(const ModInt& oth) { return n - oth.n; }
	ModInt operator*(const ModInt& oth) { return n * oth.n; }
	long long get() { return n < 0 ? n + kMod : n; }
};

ModInt pw[mxn];
int col[mxn], cnt[2];
vector<vector<int>> adj;
bool bad;

void dfs(int v) {
	cnt[col[v]]++;
	for (int u : adj[v]) {
		if (col[u] == 1 - col[v]) continue;
		if (col[u] != -1) {bad = true; continue;}
		col[u] = 1 - col[v]; dfs(u);
	}
}
void init(int n) {
	bad = false;
	adj.clear(); adj.resize(n);
	fill(col, col + n, -1);
}
int solve() {
	int n, m;
	cin >> n >> m;
	init(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	ModInt ans = 1;
	for (int i = 0; i < n; i++) {
		if (col[i] != -1) continue;
		cnt[0] = cnt[1] = 0;
		col[i] = 0; dfs(i);
		if (bad) return 0;
		ans = ans * (pw[cnt[0]] + pw[cnt[1]]);
	}
	return ans.get();
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	pw[0] = 1;
	for (int i = 1; i < mxn; i++)
		pw[i] = pw[i - 1] * 2;
	int t; cin >> t;
	while (t--) cout << solve() << endl;
}