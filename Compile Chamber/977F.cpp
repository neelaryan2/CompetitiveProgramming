#include <bits/stdc++.h>
using namespace std;

int main() {
	#ifdef LOCAL
	    freopen("in.txt", "r", stdin);
	    freopen("out.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	int a[n], nxt[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	map<int, int> pos;
	bool vis[n];
	for (int i = n - 1; i >= 0; i--) {
		pos[a[i]] = i; vis[i] = false;
		if (pos.find(a[i] + 1) == pos.end()) nxt[i] = -1;
		else nxt[i] = pos[a[i] + 1];
	}
	int ind = 0, mx = 0;
	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;
		int j = i, cnt = 0;
		while (j != -1) {
			vis[j] = true;
			j = nxt[j], cnt++;
		}
		if (cnt > mx) {mx = cnt, ind = i;}
	}
	cout << mx << endl;
	while (ind != -1)
		cout << ind + 1 << " ", ind = nxt[ind];
	cout << endl;
}