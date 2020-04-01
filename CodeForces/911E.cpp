#include<bits/stdc++.h>
using namespace std;
int n, k;
vector<int> p;
bool solve(int i, int s, int e) {
	if (s > e) return true;
	if (i > k) {
		int tmp = e;
		for (int j = i; ; j++)
			if (tmp == s - 1) break;
			else p[j] = tmp--;
		return true;
	}
	if (p[i] < s || p[i] > e) return false;
	return solve(i + 1, s, p[i] - 1) && solve(i + 1 + p[i] - s, p[i] + 1, e);
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	p.assign(n + 1, 0);
	for (int i = 1; i <= k; i++)
		cin >> p[i];
	bool flag = solve(1, 1, n);
	if (!flag) {
		cout << -1 << endl;
		return 0;
	}
	for (int i : p) if (i != 0) cout << i << " "; cout << endl;
}