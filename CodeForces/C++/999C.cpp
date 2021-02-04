#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void disp(vector<int> a) {
	for (int i : a)
		cout << i;
	cout << endl;
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, k; string s;
	cin >> n >> k >> s;
	vector<int> cnt(26, 0);
	for (auto c : s)
		cnt[c - 'a']++;
	for (int& c : cnt) {
		int sub = min(k, c);
		c -= sub;
		k -= sub;
		if (k == 0) break;
	}
	string ans;
	for (int i = n - 1; i >= 0; i--) {
		if (cnt[s[i] - 'a'] == 0) continue;
		ans += s[i]; cnt[s[i] - 'a']--;
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
}