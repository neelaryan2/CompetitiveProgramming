#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
typedef long long ll;
typedef pair<ll, ll> pll;
#define S second
#define F first
#define f(i,j,k,l) for(ll i =(ll)j; i!=(ll)k; i = i + l)
#define endl '\n'
#define hashint ll

typedef pair<hashint, hashint> phi;

phi getHash(string& s) {
	phi hash = {0, 0};
	hashint pw1 = 1, pw2 = 1;
	f(i, 0, s.size(), 1) {
		hash.F = hash.F + pw1 * s[i];
		hash.S = hash.S + pw2 * s[i];
		pw1 = pw1 * 31;
		pw2 = pw2 * 53;
	}
	return hash;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	set<pll> hashes;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		phi p = getHash(s);
		hashes.insert({p.F, p.S});
	}
	f(i, 0, m, 1) {
		string s;
		cin >> s;
		phi hash = getHash(s);
		bool fo = 0;
		hashint pw1 = 1, pw2 = 1;
		for (int j = 0; j < s.size(); j++) {
			f(k, 0, 3, 1) {
				hashint c = k + 'a' - s[j];
				if (c == 0) continue;
				phi res; pll p;
				res.F = hash.F + c * pw1;
				res.S = hash.S + c * pw2;
				p.F = res.F;
				p.S = res.S;
				auto it = hashes.lower_bound(p);
				if ( *it == p) fo = true;
				if (fo) break;
			}
			pw1 = pw1 * 31;
			pw2 = pw2 * 53;
			if (fo) break;
		}
		puts(fo ? "YES" : "NO");
	}
}
// struct segtree {
// 	vector<int> t;
// 	int n;
// 	segtree(int m) {n = m; t.assign(4 * n, 0);}
// 	void build_aux(vector<int>& a, int v, int tl, int tr) {
// 		if (tl == tr) {t[v] = a[tl]; return;}
// 		int tm = (tl + tr) / 2;
// 		build_aux(a, v * 2, tl, tm);
// 		build_aux(a, v * 2 + 1, tm + 1, tr);
// 		t[v] = t[v * 2] + t[v * 2 + 1];
// 	}
// 	int query_aux(int v, int tl, int tr, int l, int r) {
// 		if (l > r) return 0;
// 		if (l == tl && r == tr) return t[v];
// 		int tm = (tl + tr) / 2;
// 		return query_aux(v * 2, tl, tm, l, min(r, tm))
// 		       + query_aux(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
// 	}
// 	void update_aux(int v, int tl, int tr, int pos, int new_val) {
// 		if (tl == tr) {t[v] = new_val; return;}
// 		int tm = (tl + tr) / 2;
// 		if (pos <= tm)
// 			update_aux(v * 2, tl, tm, pos, new_val);
// 		else
// 			update_aux(v * 2 + 1, tm + 1, tr, pos, new_val);
// 		t[v] = t[v * 2] + t[v * 2 + 1];
// 	}
// 	void build(vector<int>& a) {
// 		build_aux(a, 1, 0, n - 1);
// 	}
// 	void update(int i, int x) {
// 		update_aux(1, 0, n - 1, i, x);
// 	}
// 	int query(int l, int r) {
// 		return query_aux(1, 0, n - 1, l, r);
// 	}
// };

// vector<int> arr(n);
// vector<int> sums(rt + 1);
// void update(int i, int j, int x) {
// 	int n = arr.size();
// 	if (i > j) return;
// 	if (i < 0) return update(0, j);
// 	if (j >= n) return update(i, n - 1);
// 	int rt = sqrt(n);
// 	int ri = i / rt, rj = j / rt;
// 	if (ri == rj) {
// 		for (int it = i; it <= j; it++) {
// 			arr[it] += x;
// 			sums[ri] += x;
// 		}
// 		return;
// 	}
// 	for (int it = ++ri; it < rj; it++)
// 		sums[it] += rt * x;
// 	update(i, ri * rt - 1);
// 	update(rj * rt, j);
// }
// int query(int i, int j) {
// 	int n = state.size();
// 	if (i > j) return 0;
// 	if (i < 0) return query(0, j);
// 	if (j >= n) return query(i, n - 1);
// 	int rt = sqrt(n);
// 	int ri = i / rt, rj = j / rt;
// 	int ans = 0;
// 	if (ri == rj) {
// 		for (int it = i; it <= j; it++)
// 			ans += arr[it];
// 		return ans;
// 	}
// 	for (int it = ++ri; it < rj; it++)
// 		ans += sums[it];
// 	ans += query(i, ri * rt - 1);
// 	ans += query(rj * rt, j);
// 	return ans;
// }