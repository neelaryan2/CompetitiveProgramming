#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define mp make_pair
#define fi first
#define se second
#define vi vector<int>
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	int a[n];
	vi adj[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int mx = *max_element(a, a + n);
	int ans = mx + 2;
	int tot0 = (a[0] == mx);
	int tot1 = (a[0] == mx - 1);
	for (int i = 1; i < n; i++) {
		tot0 += (a[i] == mx);
		tot1 += (a[i] == mx - 1);
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	for (int i = 0; i < n; i++) {
		int c0 = 0, c1 = 0;
		if (a[i] == mx) c0++, tot0--;
		if (a[i] == mx - 1) tot1--;
		for (int j : adj[i]) {
			if (a[j] == mx) c1++, tot0--;
			if (a[j] == mx - 1) c0++, tot1--;
		}
		if (tot0 > 0) ans = min(ans, mx + 2);
		else if (c1 > 0 || tot1 > 0) ans = min(ans, mx + 1);
		else if (c0 > 0) ans = min(ans, mx);
		if (a[i] == mx) tot0++;
		if (a[i] == mx - 1) tot1++;
		for (int j : adj[i]) {
			if (a[j] == mx) tot0++;
			if (a[j] == mx - 1) tot1++;
		}
	}
	cout << ans << endl;
}