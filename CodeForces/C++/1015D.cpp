#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n, k, s;
	cin >> n >> k >> s;
	if (s < k || s > (n - 1)*k) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	ll curr = 1;
	while (s - n + 1 >= k) {
		s -= n - 1; k--; curr = n + 1 - curr;
		cout << curr << " ";
	}
	if (s != k) {
		curr = (curr == n) ? n - s + k - 1 : s - k + 2;
		s -= s - k + 1; k--;
		cout << curr << " ";
	}
	bool flag = (curr != n);
	while (s != 0) {
		if (flag) curr++; else curr--;
		flag = !flag;
		cout << curr << " ";
		s--, k--;
	}
	cout << endl;
}