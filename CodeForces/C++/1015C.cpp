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
	int n, m;
	cin >> n >> m;
	vector<ll> a(n), b(n);
	ll need = -m;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		need += a[i];
		b[i] = a[i] - b[i];
	}
	sort(b.rbegin(), b.rend());
	int cnt = 0;
	while (cnt < n && need > 0)
		need -= b[cnt++];
	cout << ((need > 0) ? -1 : cnt) << endl;
}