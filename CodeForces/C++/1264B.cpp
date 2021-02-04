#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, a, b) for (int i = a; i < b; i++)
#define rfor(i, b, a) for (int i = b; i > a; i--)
#define rep(i, n) for (int i = 0; i < n; i++)
#define forv(i, v) for (auto i = v.begin(); i != v.end(); i++)
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const int N = int(1e9);
vector<int> ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a[4], b[4], x;
	rep(i, 4) cin >> a[i];
	rep(j, 4) { //ans starts with j
		ans.clear();
		rep(i, 4) b[i] = a[i];
		if (b[j] == 0) continue;
		x = j;
		while (1) {
			ans.pb(x); b[x]--;
			if (x != 0 && b[x - 1] != 0) x--;
			else if (x != 3 && b[x + 1] != 0) x++;
			else break;
		}
		if (!accumulate(b, b + 4, 0)) goto yes;
	}
	cout << "NO" << endl; return 0;
yes:
	cout << "YES" << endl;
	rep(i, ans.size()) cout << ans[i] << " ";
	cout << endl;
	return 0;
}
