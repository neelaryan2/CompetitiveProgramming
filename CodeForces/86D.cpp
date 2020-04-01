#include<bits/stdc++.h>
using namespace std;
using pii = pair<pair<int, int>, int>;
using ll = long long;
#define fi first
#define se second
const int inf = 1e6 + 5;

int rt;
ll sum = 0;
vector<int> cnt(inf, 0), a;
bool cmp(pii a, pii b) {
	if (a.fi.fi / rt != b.fi.fi / rt) return a.fi.fi / rt < b.fi.fi / rt;
	else return a.fi.se < b.fi.se;
}
void add(int idx) {
	int el = a[idx];
	sum += (2LL * (cnt[el]++) + 1) * 1LL * el;
}
void del(int idx) {
	int el = a[idx];
	sum -= (2LL * (cnt[el]--) - 1) * 1LL * el;
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, t;
	cin >> n >> t;
	rt = sqrt(n);
	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector<pii> q(t);
	vector<ll> ans(t);
	for (int i = 0; i < t; i++) {
		int l, r; cin >> l >> r;
		q[i] = {{l - 1, r - 1}, i};
	}
	sort(q.begin(), q.end(), cmp);
	int L = 0, R = -1; sum = 0;
	for (pii p : q) {
		int l = p.fi.fi, r = p.fi.se;
		while (L < l) del(L++);
		while (L > l) add(--L);
		while (R < r) add(++R);
		while (R > r) del(R--);
		ans[p.se] = sum;
	}
	for (ll i : ans) cout << i << endl;
}