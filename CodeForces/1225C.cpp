#include<bits/stdc++.h>
using namespace std;

#define popcnt __builtin_popcount

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, p, ans = -1;
	cin >> n >> p;
	for (int i = 1; i < 33; i++) {
		if (n - i * p < i) continue;
		if (popcnt(n - i * p) > i) continue;
		ans = i; break;
	}
	cout << ans << endl;
}