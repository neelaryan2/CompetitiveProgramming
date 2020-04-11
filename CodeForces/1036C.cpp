#include<bits/stdc++.h>
using namespace std;

using ll = long long;
ll get(ll k, int lvl) {
	ll aux = (k * (k - 1)) / 2, res = 0;
	if (lvl >= 0) res += 1;
	if (lvl >= 1) res += 9 * k;
	if (lvl >= 2) res += aux * 81;
	if (lvl >= 3) res += aux * (k - 2) * 243;
	return res;
}
ll solve(ll k) {
	stack<int> st; ll ans = 0, lvl = 3;
	while (k) st.push(k % 10), k /= 10;
	while (!st.empty()) {
		ll c = st.top(); st.pop();
		if (c == 0) continue;
		ans += get(st.size(), lvl);
		if (--lvl < 0) break;
		ans += get(st.size(), lvl) * (c - 1);
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
	while (t--) {
		ll l, r; cin >> l >> r;
		cout << solve(r + 1) - solve(l) << endl;
	}
}