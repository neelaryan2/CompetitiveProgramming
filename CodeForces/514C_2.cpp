#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define mp make_pair
#define fi first
#define se second
#define vi vector<int>
const int alph = 3;
const int kMod = 1700000009;
struct ModInt {
	long long n;
	ModInt(long long n = 0) : n(n % kMod) {}
	ModInt operator+(const ModInt& oth) { return n + oth.n; }
	ModInt operator-(const ModInt& oth) { return n - oth.n; }
	ModInt operator*(const ModInt& oth) { return n * oth.n; }
	long long get() { return n < 0 ? n + kMod : n; }
};
using pmi = pair<ModInt, ModInt>;
pmi getHash(string& s) {
	pmi hash = mp(0, 0);
	ModInt pw1 = 1, pw2 = 1;
	for (int i = 0; i < s.size(); i++) {
		hash.fi = hash.fi + pw1 * s[i];
		hash.se = hash.se + pw2 * s[i];
		pw1 = pw1 * 31;
		pw2 = pw2 * 53;
	}
	return hash;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	set<pii> hashes;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		pmi p = getHash(s);
		hashes.insert(mp(p.fi.get(), p.se.get()));
	}
	for (int i = 0; i < m; i++) {
		string s; cin >> s;
		pmi hash = getHash(s);
		bool found = false;
		ModInt pw1 = 1, pw2 = 1;
		for (int j = 0; j < s.size(); j++) {
			for (int k = 0; k < alph; k++) {
				ModInt c = k + 'a' - s[j];
				if (c.get() == 0) continue;
				pmi res; pii p;
				res.fi = hash.fi + c * pw1;
				res.se = hash.se + c * pw2;
				p.fi = res.fi.get();
				p.se = res.se.get();
				auto it = hashes.lower_bound(p);
				if (*it == p) found = true;
				if (found) break;
			}
			pw1 = pw1 * 31;
			pw2 = pw2 * 53;
			if (found) break;
		}
		puts(found ? "YES" : "NO");
	}
}