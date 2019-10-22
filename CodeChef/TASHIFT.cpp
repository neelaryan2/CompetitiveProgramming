#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> lps;
void kmp(string const& s) {
	for (int i = 0; i < s.length(); i++)
		lps.push_back(0);
	for (int i = 1; i < s.length(); i++) {
		int j = lps[i - 1];
		while (j > 0 && s[i] != s[j])
			j = lps[j - 1];
		if (s[i] == s[j])
			j++;
		lps[i] = j;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, ind, max = 0;
	string a, b;
	cin >> n >> a >> b;
	kmp(a + '$' + b);
	for (int i = (int)a.length() + 1; i < lps.size(); i++) {
		if (lps[i] > max) {
			max = lps[i];
			ind = i;
		}
	}
	cout << -a.length() + ind - lps[ind] << endl;
	return 0;
}