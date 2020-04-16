#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, m, k;
bool check(ll c) {
	ll lesser = 0;
	for (int i = 1; i <= n; i++)
		lesser += min((c - 1) / i, m);
	return lesser < k;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> k;
	if (m < n) swap(m, n);
	ll lo = 1, hi = m * n + 1, mid;
	while (lo < hi - 1) {
		mid = lo + (hi - lo) / 2;
		if (check(mid)) lo = mid;
		else hi = mid;
	}
	cout << lo << endl;
}