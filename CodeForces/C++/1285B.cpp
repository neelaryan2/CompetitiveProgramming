#include<bits/stdc++.h>
using namespace std;

#define eb emplace_back

inline bool is() {
	int n; cin >> n;
	long long p = 0, s = 0;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++) {
		p += a[i]; s += a[n - i - 1];
		if (p <= 0 || s <= 0) return false;
	}
	return true;
}
int main() {
	int t; cin >> t;
	while (t--)
		if (is()) puts("YES");
		else puts("NO");
}