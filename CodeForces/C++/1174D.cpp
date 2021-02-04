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
vector<int> pref;
vector<bool> used;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, x; cin >> n >> x;
	int p = 1 << n, l = 0;
	used.resize(p); pref.push_back(0);
	forn(i, 1, p) used[i] = false;
	used[0] = true;
	forn(i, 1, p) {
		used[i] = true;
		int j = x ^ i;
		if (j >= p) goto push;
		if (!used[j]) goto push;
		continue;
push:
		pref.push_back(i), l++;
	}
	cout << l << endl;
	if (!l) return 0;
	forn(i, 1, l + 1) cout << (pref[i] ^ pref[i - 1]) << " ";
	cout << endl;
	return 0;
}