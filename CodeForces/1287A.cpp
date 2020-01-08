#include<bits/stdc++.h>
using namespace std;

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int t; cin >> t;
	while (t--) {
		int n, i = 0; string s;
		cin >> n >> s;
		int cnt = 0, ans = 0;
		while (s[i] == 'P') {i++;}
		for (; i < s.size(); i++)
			if (s[i] == 'P') cnt++;
			else ans = max(ans, cnt), cnt = 0;
		cout << max(ans, cnt) << "\n";
	}
}