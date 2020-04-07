#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		ll sum = 0;
		vector<ll> arr(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		sort(arr.rbegin(), arr.rend());
		for (int i = 0; i < n; i++)
			sum = (sum + max(arr[i] - i, 0LL)) % mod;
		cout << sum << '\n';
	}
}