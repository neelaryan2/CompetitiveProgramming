#include<bits/stdc++.h>
using namespace std;

using ll = long long;
void solve() {
	ll n, k, i = 1, v = 0;
	cin >> n >> k;
	while (v < k) v += i++;
	vector<char> ans(n, 'a');
	ans[n - i] = 'b';
	ans[n - i + v - k + 1] = 'b';
	for (auto c : ans) cout << c; cout << endl;
}
int main() {
	int t; cin >> t;
	while (t--) solve();
}