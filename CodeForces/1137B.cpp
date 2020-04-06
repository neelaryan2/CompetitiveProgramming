#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define fi first
#define se second

int kmp(string const& s) {
	int n = s.size();
	vector<int> lps(n, 0);
	for (int i = 1; i < n; i++) {
		int j = lps[i - 1];
		while (j > 0 && s[i] != s[j]) 
			j = lps[j - 1];
		if (s[i] == s[j]) j++;
		lps[i] = j;
	}
	return lps.back();
}
bool cmp(vector<int>& a, vector<int>& b) {
	for (int i = 0; i < a.size(); i++)
		if (a[i] > b[i]) return false;
	return true;
}
void sub(vector<int>& a, vector<int>& b) {
	for (int i = 0; i < a.size(); i++)
		a[i] -= b[i];
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s, t;
	cin >> s >> t;
	int k = kmp(t);
	string t1 = t.substr(0, k);
	string t2 = t.substr(k, t.size() - k);
	vector<int> cnts(2, 0), cntt1(2, 0), cntt2(2, 0);
	for (char c : s) cnts[c - '0']++;
	for (char c : t1) cntt1[c - '0']++;
	for (char c : t2) cntt2[c - '0']++;
	string ans = "";
	if (cmp(cntt1, cnts)) ans = t1, sub(cnts, cntt1);
	while (cmp(cntt2, cnts)) {
		for (char c : t2) ans += c;
		sub(cnts, cntt2);
	}
	while (cnts[0] > 0) ans += '0', cnts[0]--;
	while (cnts[1] > 0) ans += '1', cnts[1]--;
	cout << ans << endl;
}