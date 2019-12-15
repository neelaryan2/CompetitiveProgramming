#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, a, b) for (int i = a; i < b; i++)
#define rfor(i, b, a) for (int i = b; i > a; i--)
#define rep(i, n) for (int i = 0; i < n; i++)
#define forv(i, v) for (auto i = v.begin(); i != v.end(); i++)
#define all(v) v.begin(), v.end()
#define fi first
#define se second
const int N = 109;
const string str = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
char farm[N][N];
char ans[N][N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, r, c, k, j, cou, ind, rem, limit, tot;
	cin >> t;
	while (t--) {
		cin >> r >> c >> k;
		tot = j = cou = ind = 0;
		rep(i, r) rep(j, c) {
			cin >> farm[i][j];
			if(farm[i][j]=='R') tot++;
		}
		rem = tot % k; limit = 1 + (tot - 1) / k;
		rep(i, r) {
			int step = (i % 2) ? -1 : 1;
			for (; j >= 0 && j < c; j += step) {
				if (cou == limit) ind=min(ind+1,k-1), cou = 0;
				if (farm[i][j] == 'R') cou++;
				ans[i][j] = str[ind];
				if (ind >= rem) limit = tot/ k;
			}
			j-=step;
		}
		rep(i, r) {
			rep(j, c) cout << ans[i][j];
			cout << endl;
		}
	}
	return 0;
}