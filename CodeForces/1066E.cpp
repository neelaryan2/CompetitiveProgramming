#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using piii = pair<pii, int>;
using vs = vector<string>;
#define fi first
#define se second
const ll inf = 1e18;
const ll mod = 998244353;

vector<vector<int>> ans, fig, check;
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
	vector<int> a(n), b(m), ans(n, 0);
	for (int i = 0; i < n; i++) {
		char c; cin >> c;
		a[i] = c - '0';
	}
	for (int i = 0; i < m; i++) {
		char c; cin >> c;
		b[i] = c - '0';
		if (i > 0) b[i] += b[i - 1];
	}
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) continue;
		if (m - n + i < 0) continue;
		ans[i] = b[m - n + i];
	}
	reverse(ans.begin(), ans.end());
	ll outp = 0, pw = 1, res;
	for (int i = 0; i < n; i++) {
		res = (pw * ans[i]) % mod;
		outp = (outp + res) % mod;
		pw = (2 * pw) % mod;
	}
	cout << outp << endl;
}