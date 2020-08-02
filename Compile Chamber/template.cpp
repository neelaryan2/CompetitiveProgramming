#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	vector<int> a(n);
	for (int& e : a) cin >> e;
	ll funds = 1000, stocks = 0;
	for (int i = 0; i < n - 1; i++) {
		stocks = a[i] / funds;
	  	funds += max(a[i + 1] - a[i], 0) * stocks;
	}
	cout << funds << endl;
}
