#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define mp make_pair
#define fi first
#define se second

#define vi vector<int>
const int alph = 3;
const vi vec = vi(alph, -1);
vector<vi> trie(1, vec);
vi cnt(1, 0);
void add() {
	string s; cin >> s;
	int v = 0, n = s.size();
	for (int i = 0; i < n; i++) {
		int c = s[i] - 'a';
		if (trie[v][c] == -1) {
			trie.emplace_back(vec);
			cnt.emplace_back(0);
			trie[v][c] = trie.size() - 1;
		}
		v = trie[v][c];
	}
	cnt[v]++;
}
bool dfs(int v, int ind, string& s, bool used) {
	bool ans = false;
	if (ind == s.size()) return used && (cnt[v] > 0);
	for (int i = 0; i < alph; i++) {
		if (trie[v][i] == -1) continue;
		if (s[ind] - 'a' == i) ans = ans || dfs(trie[v][i], ind + 1, s, used);
		else if (!used) ans = ans || dfs(trie[v][i], ind + 1, s, true);
	}
	return ans;
}
bool query() {
	string s; cin >> s;
	return dfs(0, 0, s, false);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		add();
	for (int i = 0; i < m; i++)
		puts(query() ? "YES" : "NO");
}