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
vector<set<int>> com;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, x, y; cin >> n >> m;
	com.resize(n + 1);
	rep(i, m) {
		cin >> x >> y;
		com[x].insert(y);
		com[y].insert(x);
	}
	int ind1 = N, ind2 = N;
	forn(i, 1, n + 1)
		if (com[i].size() < n - 1) {
			ind1 = i;
			break;
		}
	if (ind1 == N) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	forn(i, 1, n + 1) {
		if (ind1 == i) continue;
		if (com[i].find(ind1) == com[i].end()) {
			ind2 = i;
			break;
		}
	}
	int num = 3;
	rep(i, n) {
		if (i == ind1 - 1) cout << 1 << " ";
		else if (i == ind2 - 1) cout << 2 << " ";
		else cout << num++ << " ";
	}
	cout << endl; num = 3;
	rep(i, n) {
		if (i == ind1 - 1) cout << 1 << " ";
		else if (i == ind2 - 1) cout << 1 << " ";
		else cout << num++ << " ";
	}
	cout << endl;
	return 0;
}