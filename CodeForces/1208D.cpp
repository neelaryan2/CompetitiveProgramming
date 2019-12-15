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
int n, power;
vector<ll> BIT, s;
vector<int> ans;

void update(int x, int val) {
	for (; x <= n ; x += x & (-x)) BIT[x] += val;
}
int find_num(ll val) {  //using binary lifting
	ll sum = 0; 	int pos = 0;
	for (int d = power; d >= 1; d >>= 1)
		if (pos + d < n && sum + BIT[pos + d] <= val)  {
			sum += BIT[pos + d];
			pos += d;
		}
	return pos + 1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n; power = 1 << int(log2(n));
	BIT.resize(n + 1); ans.resize(n); s.resize(n);
	forn(i, 1, n + 1) update(i, i), cin >> s[i - 1];
	rfor(i, n - 1, -1) {
		ans[i] = find_num(s[i]);
		update(ans[i], -ans[i]);
	}
	rep(i, n) cout << ans[i] << " ";
	cout << endl;
	return 0;
}