#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define mp make_pair
#define fi first
#define se second
#define vi vector<int>
const int kMod = 998244353;
struct ModInt {
	long long n;
	ModInt(long long n = 0) : n(n % kMod) {}
	ModInt operator+(const ModInt& oth) { return n + oth.n; }
	ModInt operator-(const ModInt& oth) { return n - oth.n; }
	ModInt operator*(const ModInt& oth) { return n * oth.n; }
	long long get() { return n < 0 ? n + kMod : n; }
};
ModInt lgpow(ModInt b, int e = -1) {
	if (b.get() == 0) return 0;
	ModInt r; e = e % (kMod - 1);
	if (e < 0) e += kMod - 1;
	for (r = 1; e; e >>= 1, b = b * b)
		if (e & 1) r = r * b;
	return r;
}
vector<ModInt> fact, invfact;
vector<ll> primes;
void factorials(int n) {
	fact.resize(n + 1, 1);
	invfact.resize(n + 1, 1);
	for (int i = 1; i <= n; ++i)
		fact[i] = fact[i - 1] * i;
	invfact[n] = lgpow(fact[n]);
	for (int i = n - 1; i >= 1; --i)
		invfact[i] = invfact[i + 1] * (i + 1);
}
ModInt get(ll num) {
	ModInt ans = 1;
	int tot = 0;
	for (ll p : primes) {
		int cnt = 0;
		while (num % p == 0)
			num /= p, cnt++;
		ans = ans * invfact[cnt];
		tot += cnt;
	}
	ans = ans * fact[tot];
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	factorials(100);
	ll D, q, u, v, g;
	cin >> D >> q;
	for (ll i = 2; i * i <= D; i++) {
		if (D % i) continue;
		while (D % i == 0) D /= i;
		primes.emplace_back(i);
		if (i != 2) i++;
	}
	if (D != 1) primes.emplace_back(D);
	while (q--) {
		cin >> u >> v;
		g = __gcd(u, v);
		u /= g; v /= g;
		ModInt ans = get(u) * get(v);
		cout << ans.get() << endl;
	}
}