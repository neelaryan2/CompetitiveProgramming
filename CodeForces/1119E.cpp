#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, a, b) for (int i = a; i < b; i++)
#define rfor(i, b, a) for (int i = b; i > a; i--)
#define rep(i, n) for (int i = 0; i < n; i++)
#define forv(i, v) for (auto i = v.begin(); i != v.end(); i++)
#define all(v) v.begin(), v.end()
#define fi first
#define se second
const int N = int(1e9);
vector<int> a;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n, p = 0, ans = 0; cin >> n;
	a.resize(n);
	rep(i, n) cin >> a[i];
	rfor(i, n - 1, -1) {
		p += a[i] / 2;
		if (a[i] % 2 && p) p--, ans++;
	}
	cout << ans + (2 * p) / 3 << endl;
	return 0;
}