#include <bits/stdc++.h>
using namespace std;
vector<int> cnt(52, -1);
bool check() {
	for (int i : cnt)
		if (i == 0) return false;
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n; cin >> n;
	vector<int> vec(n);
	for (int i = 0; i < n; i++) {
		char c; cin >> c;
		if ('a' <= c && c <= 'z') vec[i] = c - 'a';
		else vec[i] = c - 'A' + 'z' - 'a' + 1;
		cnt[vec[i]] = 0;
	}
	int l = 0, r = 0, ans = 1e9;
	while (r < n) {
		while (r < n && !check()) cnt[vec[r++]]++;
		while (l <= r && check()) cnt[vec[l++]]--;
		ans = min(ans, r - l + 1);
	}
	cout << ans << endl;
}
