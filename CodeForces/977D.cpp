#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll exp(ll a, ll k) {
	ll cnt = 0;
	while (a % k == 0)
		a /= k, cnt++;
	return cnt;
}
bool cmp(const ll& a, const ll& b) {
	ll aa = exp(a, 2), bb = exp(b, 2);
	if (aa != bb) return aa < bb;
	else return a > b;
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	ll a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n, cmp);
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}