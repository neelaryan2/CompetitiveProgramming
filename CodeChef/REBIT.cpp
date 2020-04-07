#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second

const int kMod = 998244353;
struct ModInt {
	long long n;
	ModInt(long long n = 0) : n(n % kMod) {}
	ModInt operator+(const ModInt& oth) const { return n + oth.n; }
	ModInt operator-(const ModInt& oth) const { return n - oth.n; }
	ModInt operator*(const ModInt& oth) const { return n * oth.n; }
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
struct pmm {
	ModInt x, y;
	pmm() {x = 1; y = 4;}
	pmm operator+(const pmm& oth) const {
		pmm res; res.y = y * oth.y;
		res.x = x * oth.y + y * oth.x;
		return res;
	}
	pmm operator-(const pmm& oth) const {
		pmm res; res.y = y * oth.y;
		res.x = x * oth.y - y * oth.x;
		return res;
	}
	pmm operator*(const pmm& oth) const {
		pmm res; res.y = y * oth.y;
		res.x = x * oth.x;
		return res;
	}
};
struct prob {
	pmm one;
	pmm zero;
	pmm a;
	pmm A;
};
prob my_and(const prob& a1, const prob& a2) {
	prob ans;
	ans.one = a1.one * a2.one;
	ans.a = a1.one * a2.a + a1.a * a2.one + a1.a * a2.a;
	ans.A = a1.one * a2.A + a1.A * a2.one + a1.A * a2.A;
	ans.zero = (a1.one + a1.a + a1.A + a1.zero) * (a2.one + a2.a + a2.A + a2.zero);
	ans.zero = ans.zero - (ans.a + ans.A + ans.one);
	return ans;
}
prob my_or(const prob& a1, const prob& a2) {
	prob ans;
	ans.zero = a1.zero * a2.zero;
	ans.a = a1.zero * a2.a + a1.a * a2.zero + a1.a * a2.a;
	ans.A = a1.zero * a2.A + a1.A * a2.zero + a1.A * a2.A;
	ans.one = (a1.one + a1.a + a1.A + a1.zero) * (a2.one + a2.a + a2.A + a2.zero);
	ans.one = ans.one - (ans.a + ans.A + ans.zero);
	return ans;
}
prob my_xor(const prob& a1, const prob& a2) {
	prob ans;
	ans.zero = a1.one * a2.one + a1.zero * a2.zero + a1.A * a2.A + a1.a * a2.a;
	ans.A = a1.one * a2.a + a1.a * a2.one + a1.A * a2.zero + a1.zero * a2.A;
	ans.a = a1.one * a2.A + a1.A * a2.one + a1.a * a2.zero + a1.zero * a2.a;
	ans.one = a1.one * a2.zero + a1.zero * a2.one + a1.a * a2.A + a1.A * a2.a;
	return ans;
}
void solve() {
	string s; cin >> s;
	stack<char> operators, operands;
	stack<prob> res;
	for (char c : s) {
		if (c == '&' || c == '|' || c == '^') {
			operators.push(c);
			continue;
		}
		if (c == '#') {
			prob curr;
			res.push(curr);
			continue;
		}
		if (c == ')') {
			operands.push(c);
			while (operands.top() == ')') {
				char optr = operators.top(); operators.pop();
				operands.pop();
				prob a1 = res.top(); res.pop();
				prob a2 = res.top(); res.pop();
				if (optr == '&') res.push(my_and(a1, a2));
				else if (optr == '|') res.push(my_or(a1, a2));
				else if (optr == '^') res.push(my_xor(a1, a2));
			}
			continue;
		}
		if (c == '(') {
			operands.push(c);
			continue;
		}
	}
	prob ans = res.top();
	ModInt ans0 = ans.zero.x * lgpow(ans.zero.y);
	ModInt ans1 = ans.one.x * lgpow(ans.one.y);
	ModInt ansa = ans.a.x * lgpow(ans.a.y);
	ModInt ansA = ans.A.x * lgpow(ans.A.y);
	cout << ans0.get() << " " << ans1.get() << " ";
	cout << ansa.get() << " " << ansA.get() << endl;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int t; cin >> t;
	while (t--) solve();
}