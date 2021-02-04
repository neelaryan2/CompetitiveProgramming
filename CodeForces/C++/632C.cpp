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
const int N = int(1e9);
vector<string> str;
bool comp(string a, string b) {
	return a + b < b + a;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	str.resize(n);
	rep(i, n) cin >> str[i];
	sort(all(str), comp);
	rep(i, n) cout << str[i];
	cout << endl;
	return 0;
}