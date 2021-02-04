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
const int N = int(1e9);
int pre(string s) {
	int n = sz(s);
	vector<int> pi(n, 0);
	forn(i, 1, n) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j]) 	j = pi[j - 1];
		if (s[i] == s[j])	j++;
		pi[i] = j;
	}
	return pi[n - 1];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, siz; cin >> n;
	string temp, ans; cin >> ans;
	rep(i, n - 1) {
		cin >> temp; temp += "@"; siz = sz(temp) - 1;
		forn(j, max(0, sz(ans) - siz), sz(ans))	temp += ans[j];
		forn(j, pre(temp), siz) ans += temp[j];
	}
	cout << ans << endl;
	return 0;
}