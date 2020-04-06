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
	vector<ll> p(n), s(k), ans(k, 0);
	for (int i = 0; i < n; i++)
		cin >> p[i];
	for (int i = 0; i < k; i++)
		cin >> s[i];
	ll curr = 0;
	for (ll c : p) {
		curr += c;
		while (curr >= s[0]) {
			int j = lb(all(s), curr) - s.begin();
			if (s[j] > curr) j--;
			ans[j] += curr / s[j]; curr %= s[j];
		}
	}
	for (ll i : ans) cout << i << " ";
	cout << endl << curr << endl;
}