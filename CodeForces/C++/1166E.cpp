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
int n, m, s, ind;
bool intersect;
vector<vector<bool>> d;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> m >> n;
	d.resize(m);	rep(i, m) d[i].resize(n, false);
	rep(i, m) {
		cin >> s;
		rep(j, s) cin >> ind, d[i][ind - 1] = true;
	}
	rep(i, m) forn(j, i + 1, m) {
		intersect = false;
		rep(k, n)
		if (d[i][k] && d[j][k])
		{intersect = true; break;}
		if (!intersect) goto no;
	}
	cout << "possible" << endl;
	return 0;
no: cout << "impossible" << endl;
	return 0;
}