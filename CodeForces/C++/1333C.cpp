#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	ll ans = 0, sum = 0, mx = -1;
	map<ll, ll> last;
	last[sum] = 0;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a; sum += a;
		if (last.find(sum) != last.end())
			mx = max(mx, last[sum]);
		ans += i - mx - 1;
		last[sum] = i;
	}
	cout << ans << endl;
}