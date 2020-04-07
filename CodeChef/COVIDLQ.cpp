#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
bool solve() {
	int n; cin >> n;
	int prev = -1;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0) continue;
		if (prev == -1) { prev = i; continue; }
		if (i - prev < 6) return false;
		else prev = i;
	}
	return true;
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while (t--) puts(solve() ? "YES" : "NO");
}