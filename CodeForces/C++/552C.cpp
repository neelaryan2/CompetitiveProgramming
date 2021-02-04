#include<bits/stdc++.h>
using namespace std;

int main() {
	#ifdef LOCAL
	    freopen("in.txt", "r", stdin);
	    freopen("out.txt", "w", stdout);
	#endif
	int w, m;
	cin >> w >> m;
	vector<int> a;
	while (m) a.push_back(m % w), m /= w;
	a.push_back(0);
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != 0 && a[i] != 1 && a[i] != w - 1 && a[i] != w) {
			puts("NO");
			return 0;
		}
		if (a[i] != w && a[i] != w - 1) continue;
		if (i + 1 < a.size()) a[i + 1]++;
	}
	puts("YES");
}