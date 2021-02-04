#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
using ll = long long;
using pii = pair<ll, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll inf = 2e18;
bool cmp(const pair<pii, int>& a, const pair<pii, int>& b) {
	return a.fi.fi - a.fi.se > b.fi.fi - b.fi.se;
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<pair<pii, ll>> scores(n);
	vector<pii> cpy(n);
	for (int i = 0; i < n; i++) {
		cin >> scores[i].fi.fi >> scores[i].fi.se;
		scores[i].se = i;
		cpy[i] = scores[i].fi;
	}
	sort(scores.begin(), scores.end(), cmp);
	vector<ll> p(n, 0);
	ll toty = 0, totx = 0;
	for (int i = 0; i < n; i++) {
		p[i] += 1LL * i * scores[i].fi.fi + toty;
		toty += scores[i].fi.se;
		p[n - i - 1] += 1LL * i * scores[n - i - 1].fi.se + totx;
		totx += scores[n - i - 1].fi.fi;
	}
	vector<ll> ans(n);
	for (int i = 0; i < n; i++)
		ans[scores[i].se] = p[i];
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		int curr = min(cpy[u].fi + cpy[v].se, cpy[v].fi + cpy[u].se);
		ans[u] -= curr;
		ans[v] -= curr;
	}
	for (int i = 0; i < n; i++) cout << ans[i] << " "; cout << endl;
}