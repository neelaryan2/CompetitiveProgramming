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
#define endl "\n"
const int N = int(1e9);
vi x;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, z, ind, ans = 0; cin >> n >> z;
	x.resize(n);
	rep(i, n) cin >> x[i];
	sort(all(x)); ind = n - 1;
	repr(i, n / 2)  if (x[i] + z <= x[ind]) ind--, ans++;
	cout << ans << endl;
	return 0;
}