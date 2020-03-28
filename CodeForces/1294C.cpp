#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int k = 5;

void solve() {
	int n; cin >> n;
	vector<int> div;
	for (int i = 2; i * i <= n; i++) {
		if (n % i) continue;
		div.emplace_back(i); n /= i;
		if (div.size() == 2) {
			div.emplace_back(n);
			break;
		}
	}
	bool flag = false;
	for (int i = 0; i < div.size(); i++)
		for (int j = i + 1; j < div.size(); j++)
			if (div[i] == div[j] || div[i] == 1)
				flag = true;
	if (div.size() != 3 || flag) {
		puts("NO");
		return;
	}
	puts("YES");
	for (int i : div) cout << i << " "; cout << endl;
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int t; cin >> t;
	while (t--) solve();
}