#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
using ll = long long;

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll a, b, p, x;
	cin >> a >> b >> p >> x;
	ll inva = 1, ans = 0;
	vector<ll> pw(p - 1, 1);
	for (int i = 1; i < p - 1; i++)
		inva = (inva * a) % p;
	for (int i = 1; i < p - 1; i++)
		pw[i] = (pw[i - 1] * inva) % p;
	pw.emplace_back(1);
	for (int i = 1; i < p; i++) {
		ll res = (b * pw[i]) % p;
		res = (p - 1) * ((i - res + p) % p) + i;
		if (res > x) continue;
		ans += (x - res) / (p * (p - 1)) + 1;
	}
	cout << ans << endl;
}