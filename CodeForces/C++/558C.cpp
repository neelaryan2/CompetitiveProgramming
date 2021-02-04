#include<bits/stdc++.h>
using namespace std;
const int maxb = 17;

string getBinary(int num) {
	string s;
	while (num) {
		s += (num % 2) ? '1' : '0';
		num >>= 1;
	}
	reverse(s.begin(), s.end());
	return s;
}
string getPrefix(string s1, string& s2) {
	string ans;
	for (int i = 0; i < min(s1.size(), s2.size()); i++) {
		if (s1[i] != s2[i]) break;
		ans += s1[i];
	}
	return ans;
}
int main() {
	int n; cin >> n;
	int arr[n];
	string bin[n], pref;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		bin[i] = getBinary(arr[i]);
		if (i == 0) pref = bin[0];
		else pref = getPrefix(pref, bin[i]);
	}
	for (int i = 0; i < n; i++)
		bin[i] = bin[i].substr(pref.size(), maxb + 1);
	int ans = n * (maxb + 10);
	for (int i = 0; i < maxb; i++) {
		int curr = 0;
		for (int j = 0; j < n; j++) {
			int tr = 0;
			for (char c : bin[j]) {
				if (c == '1') break;
				else tr++;
			}
			curr += bin[j].size() - i;
			if (tr < i) curr += 2 * (i - tr);
		}
		ans = min(ans, curr);
	}
	cout << ans << endl;
}