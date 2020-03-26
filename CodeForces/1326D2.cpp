#include<bits/stdc++.h>
using namespace std;

string kmp(string const& str) {
	string a = str;
	reverse(a.begin(), a.end());
	string s = str + "@" + a;
	vector<int> lps((int)s.size(), 0);
	for (int i = 1; i < s.length(); i++) {
		int j = lps[i - 1];
		while (j > 0 && s[i] != s[j]) j = lps[j - 1];
		if (s[i] == s[j]) j++;
		lps[i] = j;
	}
	return str.substr(0, lps.back());
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int n  = s.size();
		int j = 0;
		for (int i = 0; i < 1 + (n - 1) / 2; i++)
			if (s[i] == s[n - i - 1]) j++;
			else break;
		string a = s.substr(j, n - 2 * j);
		string ans1 = kmp(a);
		reverse(a.begin(), a.end());
		string ans2 = kmp(a);
		string ans = (ans1.size() > ans2.size()) ? ans1 : ans2;
		if (j > 0) ans = s.substr(0, j) + ans + s.substr(n - j, j);
		if (j == 1 + (n - 1) / 2) ans = s;
		cout << ans << "\n";
	}
}