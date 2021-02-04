#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
#define vi vector<ll>
#define sz(v) int((v).size())

const int kMod = mod;
struct ModInt {
	long long n;
	ModInt(long long n = 0) : n(n % kMod) {}
	ModInt operator+(const ModInt& oth) { return n + oth.n; }
	ModInt operator-(const ModInt& oth) { return n - oth.n; }
	ModInt operator*(const ModInt& oth) { return n * oth.n; }
	long long get() { return n < 0 ? n + kMod : n; }
};
void solve() {
	int x; cin >> x;
	string s; cin >> s;
	ModInt ans = s.size();
	for (int i = 0; i < x; i++) {
		ll c = s[i] - '0', curr = s.size();
		ans = ans + (ans - i - 1) * (c - 1);
		if (curr == x) continue;
		while (--c) {
			int j = i + 1;
			while (s.size() < x && j < curr)
				s.push_back(s[j++]);
		}
	}
	cout << ans.get() << endl;
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while (t--) solve();
}
