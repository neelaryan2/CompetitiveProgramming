#include<bits/stdc++.h>
using namespace std;

int main() {
	int n = 100;
	while(n--) cout<<1<<endl;
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