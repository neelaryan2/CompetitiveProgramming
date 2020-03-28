#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int k = 5;


int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, k;
	cin >> n >> k;
	vector<int> vec;
	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		if (c < n - k + 1) continue;
		vec.emplace_back(i);
	}
	sort(vec.begin(), vec.end());
	ll val = n, ans = 1;
	for (int i = 1; i < k; i++) {
		ans = (ans * (vec[i] - vec[i - 1])) % 998244353;
		val += i + n - k;
	}
	cout << val << " " << ans << endl;
}