#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 1;
vector<priority_queue<int>> num(maxn);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, k, ans = 1e9;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a, mov = 0;	cin >> a;
		while (a) {
			num[a].push(mov);
			if (num[a].size() > k) num[a].pop();
			a >>= 1, mov++;
		}
	}
	for (int i = 0; i < maxn; i++) {
		if (num[i].size() != k) continue;
		int curr = 0;
		while (!num[i].empty())
			curr += num[i].top(), num[i].pop();
		ans = min(curr, ans);
	}
	cout << ans << endl;
}