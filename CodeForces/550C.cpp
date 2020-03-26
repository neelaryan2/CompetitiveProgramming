#include<bits/stdc++.h>
using namespace std;
string s;
bool check(int i, int j, int k) {
	int num = 0;
	if (i != -1) num += 100 * (s[i] - '0');
	if (j != -1) num += 10 * (s[j] - '0') ;
	if (k != -1) num += (s[k] - '0');
	return (num % 8 == 0);
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	cin >> s;
	for (int k = 0; k < s.size(); k++)
		if (check(-1, -1, k)) {
			puts("YES");
			cout << s[k] << endl;
			return 0;
		}
	for (int j = 0; j < s.size(); j++)
		for (int k = j + 1; k < s.size(); k++)
			if (check(-1, j, k)) {
				puts("YES");
				cout << s[j] << s[k] << endl;
				return 0;
			}
	for (int i = 0; i < s.size(); i++)
		for (int j = i + 1; j < s.size(); j++)
			for (int k = j + 1; k < s.size(); k++)
				if (check(i, j, k)) {
					puts("YES");
					cout << s[i] << s[j] << s[k] << endl;
					return 0;
				}
	puts("NO");
}