#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; cin >> n; n++;
	ll ans = (1LL << n) - 2;
	cout << ans << endl;
}