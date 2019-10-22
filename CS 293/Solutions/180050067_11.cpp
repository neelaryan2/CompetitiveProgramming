#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll,ll>
#define x first
#define y second
const int p1 = 31;
const int p2 = 37;
const int MOD = 1e9 + 9;
vector<int> parent, cap;
vector<list<ii>> cache;
vector<map<ii, list<ii>::iterator>> locations;
ll ans = 0;
ii hashing(string const& s) {
	ii val = make_pair(0, 0);
	ll pow1 = 1, pow2 = 1;
	for (char c : s) {
		val.x = (val.x + (c - 'a' + 1) * pow1) % MOD;
		pow1 = (pow1 * p1) % MOD;
		val.y = (val.y + (c - 'a' + 1) * pow2) % MOD;
		pow2 = (pow2 * p2) % MOD;
	}
	return val;
}
void traverse(ii const& hs, int v) {
	ans += 1 + int(log2(cap[v]));
	if (!v) return;
	auto it = locations[v].find(hs);
	if (it == locations[v].end()) {
		cache[v].push_front(hs);
		locations[v][hs] = cache[v].begin();
		if (int(cache[v].size()) > cap[v]) {
			locations[v].erase(cache[v].back());
			cache[v].pop_back();
		}
		traverse(hs, parent[v]);
	} else {
		cache[v].erase(it->y);
		cache[v].push_front(hs);
		locations[v][hs] = cache[v].begin();
		return;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, temp;
	cin >> n >> m;
	parent.push_back(-1);
	for (int i = 1; i < n; i++)
		cin >> temp, parent.push_back(temp);
	cap.push_back(m);
	for (int i = 1; i < n; i++)
		cin >> temp, cap.push_back(temp);
	for (int i = 0; i < n; i++) {
		cache.emplace_back();
		locations.emplace_back();
	}
	string query;
	for (int i = 0; i < m; i++) {
		cin >> query >> temp;
		traverse(hashing(query), temp);
	}
	cout << ans << endl;
}