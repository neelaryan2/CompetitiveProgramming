#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, a, b) for (int i = a; i < b; i++)
#define rfor(i, b, a) for (int i = b; i > a; i--)
#define rep(i, n) for (int i = 0; i < n; i++)
#define forv(i, v) for (int i = 0; i < v.size(); i++)
#define all(v) v.begin(), v.end()
#define fi first
#define se second
const int N = int(1e9);
vector<ll> hei;
ll t, n, k;

bool possible(ll each) {
	ll prev = 0, cnt = 0, curr = 0;
	rep(i, n) {
		curr = hei[i];
		if (curr >= each - prev) {
			curr -= each - prev;
			cnt++; prev = 0;
		}
		cnt += curr / each;
		prev = curr % each;
		if (cnt >= k) return true;
	}
	return cnt >= k;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	ll tot;
	while (t--) {
		hei.clear(); tot = 0;
		cin >> n >> k;
		hei.resize(n);
		rep(i, n) cin >> hei[i], tot += hei[i];
		ll l = 0, r = 1 + tot / k, mid = 0;
		while (l < r - 1) {
			mid = (l + r) / 2;
			if (possible(mid)) l = mid;
			else r = mid;
		}
		cout << l*k << endl;
	}
	return 0;
}