#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ppi = pair<pii, pii>;
#define all(v) (v).begin(),(v).end()
#define lb lower_bound
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
const int N = 1e6 + 10;
const int kMod = 1e9 + 7;

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

int n, q, LOGN, sqrtN, T;
int least[N];
vector<vector<int>> adj, P;
vector<int> depth, tin, tout, arr, val;
vector<int> primes(N, 0);
vector<vector<pii>> factors;
vector<ModInt> inv(N);
ModInt curr = 1;

bool cmp(ppi& a, ppi& b) {
	int ak = 1 + ((a.fi.fi - 1) / (sqrtN + 1));
	int bk = 1 + ((b.fi.fi - 1) / (sqrtN + 1));
	if (ak != bk) return ak < bk;
	else if (a.fi.se != b.fi.se) return a.fi.se < b.fi.se;
	else return a.fi.fi < b.fi.fi;
}
void sieve() {
	for (int i = 2; i < N; i += 2)
		least[i] = 2;
	for (int i = 3; i < N; i += 2) {
		if (least[i]) continue;
		least[i] = i;
		if (N / i < i) continue;
		int j = i * i;
		while (j < N) least[j] = i, j += i;
	}
	for (int i = 0; i < N; i++)
		inv[i] = lgpow(i);
}
void init() {
	cin >> n;
	T = 0; curr = 1;
	int j = 0;
	for (; (1 << j) < n; j++);
	LOGN = j;
	j = sqrt(2 * n);
	sqrtN = j;
	adj.clear(); P.clear(); arr.clear(); factors.clear();
	tin.clear(); tout.clear(); depth.clear(); val.clear();
	adj.resize(n);
	P.resize(n, vector<int>(LOGN));
	depth.resize(n);
	tin.resize(n);
	tout.resize(n);
	factors.resize(n);
	arr.resize(2 * n);
	primes.assign(N, 0);
	val.assign(n, 0);
}
void dfs(int v, int pr = -1) {
	P[v][0] = pr;
	tin[v] = T++;
	for (int u : adj[v]) {
		if (u == pr) continue;
		depth[u] = depth[v] + 1;
		dfs(u, v);
	}
	tout[v] = T++;
}
int lca(int p, int q) {
	if (depth[p] < depth[q]) swap(p, q);
	for (int i = LOGN - 1; i >= 0; i--)
		if (depth[p] - depth[q] >= (1 << i))
			p = P[p][i];
	if (p == q)	return p;
	for (int i = LOGN - 1; i >= 0; i--)
		if (P[p][i] != -1 && P[p][i] != P[q][i])
			p = P[p][i], q = P[q][i];
	return P[p][0];
}
void update(int pos, int c) {
	val[arr[pos]] += c;
	if (val[arr[pos]] == 2 && c == 1) c = -1;
	if (val[arr[pos]] == 1 && c == -1) c = 1;
	for (pii pi : factors[arr[pos]]) {
		curr = curr * inv[primes[pi.fi] + 1];
		primes[pi.fi] += c * pi.se;
		curr = curr * (primes[pi.fi] + 1);
	}
}
void solve() {
	init();
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].eb(v);
		adj[v].eb(u);
	}
	for (int i = 0; i < n; i++) {
		ll num; cin >> num;
		while (num > 1) {
			int p = least[num], cnt = 0;
			while (num % p == 0) num /= p, cnt++;
			factors[i].eb(mp(p, cnt));
		}
	}
	depth[0] = 0; dfs(0);
	
	for (int j = 1; j < LOGN; j++)
		for (int i = 0; i < n; i++)
			if (P[i][j - 1] != -1)
				P[i][j] = P[P[i][j - 1]][j - 1];
	
	for (int i = 0; i < n; i++)
		arr[tin[i]] = arr[tout[i]] = i;

	cin >> q;
	vector<ll> ans(q);
	vector<ppi> queries(q);
	for (int i = 0; i < q; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		if (tin[u] > tin[v]) swap(u, v);
		int pr = lca(u, v);
		pii p1, p2;
		if (u == pr) {
			p1 = mp(tin[u], tin[v]);
			p2 = mp(-1, i);
		} else {
			p1 = mp(tout[u], tin[v]);
			p2 = mp(tin[pr], i);
		}
		queries.eb(mp(p1, p2));
	}
	sort(all(queries), cmp);
	int L = 0, R = -1;
	for (ppi p : queries) {
		int l = p.fi.fi, r = p.fi.se;
		int pr = p.se.fi, id = p.se.se;
		while (R < r) update(++R, 1);
		while (L < l) update(L++, -1);
		while (L > l) update(--L, 1);
		while (R > r) update(R--, -1);
		ModInt tmp = curr;
		if (pr != -1) {
			for (pii pi : factors[arr[pr]]) {
				tmp = tmp * inv[primes[pi.fi] + 1];
				tmp = tmp * (primes[pi.fi] + pi.se + 1);
			}
		}
		ans[id] = tmp.get();
	}
	for (ll i : ans) cout << i << endl;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	sieve();
	int t; cin >> t;
	while (t--) solve();
}