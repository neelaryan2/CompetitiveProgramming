#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	string s, tmp; cin >> s;
	int n = s.size(), j = 0;
	vector<int> ind;
	for (int i = 0; i < n; i = j) {
		tmp += s[i];
		while (j < n && s[j] == s[i]) j++;
		if (j - i > 1) {
			ind.emplace_back(tmp.size() - 1);
			tmp += s[i];
		}
	}
	if (ind.size() < 2) {
		cout << tmp << endl;
		return 0;
	}
	for (int i = 0; i < ind.size() - 1; i++) {
		int j = i + 1;
		while (j < ind.size() && ind[j] - ind[j - 1] == 2) j++;
		for (int k = i + 1; k < j; k += 2)
			tmp[ind[k]] = '@';
		i = j - 1;
	}
	for (char c : tmp) if (c != '@') cout << c;
	cout << endl;
}