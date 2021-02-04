#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define fi first
#define se second
const int inf = 1e9;

int solve() {
	int n, x;
	cin >> n >> x;
	vector<int> p(n + 1, 0);
	int found = (x == 0);
	for (int i = 1; i <= n; i++) {
		char c; cin >> c;
		p[i] = (c == '0') ? 1 : -1;
		p[i] += p[i - 1];
		if (p[i] == x) found = 1;
	}
	int tot = p.back(), ans = 0;
	p.pop_back();
	if (tot == 0) return -found;
	for (int i : p) {
		if (abs(i - x) % abs(tot) != 0) continue;
		if ((x - i) / tot >= 0) ans++;
	}
	return ans;
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while (t--) cout << solve() << endl;
}