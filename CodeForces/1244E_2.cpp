#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, a, b) for (int i = a; i < b; i++)
#define rfor(i, b, a) for (int i = b; i > a; i--)
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n - 1; i >=0; i--)
#define forv(i, v) for (auto i = v.begin(); i != v.end(); i++)
#define all(v) v.begin(), v.end()
#define sz(v) int(v.size())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define pp pair<int, int>
#define vi vector<int>
const int N = int(1e9);
ll n, k, p;
vi a;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	a.resize(n);
	rep(i, n) cin >> a[i];
	sort(all(a));
	int l = 1, r = 1, mn = a[0], mx = a[n - 1];
	while (1) {
		if (mx == mn) break;
		while (a[l] == mn) l++;
		while (a[n - r - 1] == mx) r++;
		if (l < r) {
			p = min(k / l, (ll)a[l] - mn);
			if (!p) break;
			k -= p * l;	mn += p;
		}
		else {
			p = min(k / r, (ll)mx - a[n - r - 1]);
			if (!p) break;
			k -= p * r;	mx -= p;
		}
	}
	cout << mx - mn << endl;
	return 0;
}