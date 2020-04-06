#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define fi first
#define se second

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ll x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	ll ans = abs(y1 - y2) / 2 + 1;
	ans *= abs(x1 - x2) + 1;
	ans -= abs(x1 - x2) / 2;
	ans -= abs(x1 - x2) % 2;
	cout << ans << endl;
}
