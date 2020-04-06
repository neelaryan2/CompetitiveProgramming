#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se seond
#define all(v) (v).begin(),(v).end()
#define lb lower_bound
#define ub upper_bound

using ll = long long;
using pii = pair<int, int>;

const int k = 5;

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int mx = *max_element(all(a));
	ll g = 0, sum = 0;
	for (ll i : a) {
		sum += mx - i;
		if (mx == i) continue;
		g = __gcd(g, mx - i);
	}
	cout << sum / g << " " << g << endl;
}