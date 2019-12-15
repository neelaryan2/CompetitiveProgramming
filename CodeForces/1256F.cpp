#include<bits/stdc++.h>
using namespace std;
int n;
string s, t;
void swap(int a, int b) {
	char temp = t[a];
	t[a] = t[b];
	t[b] = temp;
	temp = s[n - 1];
	s[n - 1] = s[n - 2];
	s[n - 2] = temp;
}
int main() {
	int te;
	cin >> te;
	while (te--) {
		cin >> n >> s >> t;
		if (n > 26) {cout << "YES" << endl; continue;}
		string a = s, b = t;
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		if (a != b) {cout << "NO" << endl; continue;}
		bool c = false;
		for (int i = 1; i < n; i++) {
			if (a[i] == a[i - 1])
				c = true;
		}
		if (c) {cout << "YES" << endl; continue;}
		for (int i = 0; i < n; i++) {
			if (s[i] == t[i]) continue;
			int ind = -1;
			for (int j = i + 1; j < n; j++) {
				if (s[i] == t[j]) {
					ind = j;
					break;
				}
			}
			for (int j = ind; j > i; j--) {
				swap(j, j - 1);
			}
		}
		if (s[n - 1] == t[n - 1] && s[n - 2] == t[n - 2])
			cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}