#include<bits/stdc++.h>
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
	ll x, ans = 0, val = 0; 
	cin >> x; x = abs(x);
	while (val < x || val % 2 != x % 2) val += ++ans;
	cout << ans << endl;
}