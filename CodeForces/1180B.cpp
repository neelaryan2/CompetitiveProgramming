#include<bits/stdc++.h>
using namespace std;

int main() {
	#ifdef LOCAL
	    freopen("in.txt", "r", stdin);
	    freopen("out.txt", "w", stdout);
	#endif
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] < 0) continue;
		a[i] = -a[i] - 1;
	}
	auto it = min_element(a.begin(), a.end());
	if (n % 2) *it = -(*it) - 1;
	for (int i : a) cout << i << " ";
	cout << endl;
}