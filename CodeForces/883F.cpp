#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; cin >> n;
	vector<string> vec(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i];
	map<string, int> mp;
	for (string s : vec) {
		s += '@';
		int cnt = 1; string rep;
		for (int i = 1; i < s.size(); i++) {
			if (s[i] != s[i - 1]) {
				char c = s[i - 1];
				if (s[i] == 'h' && c == 'k') {
					cnt = 1; continue;
				} else if (c == 'u') cnt *= 2, c = 'o';
				for (int i = 0; i < cnt; i++)
					rep += c;
				cnt = 1;
			} else cnt++;
		}
		mp[rep]++;
	}
	cout << mp.size() << endl;
}