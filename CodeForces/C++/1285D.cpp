#include<bits/stdc++.h>
using namespace std;

#define eb emplace_back

int split(vector<int> t, int cur) {
	if (cur < 0) return 0;
	if (t.size() == 0) return 2e9;
	vector<int> on, off;
	for (int c : t)
		if ((c >> cur) & 1) on.eb(c);
		else off.eb(c);
	int ans = min(split(on, cur - 1), split(off, cur - 1));
	if (!on.empty() && !off.empty()) ans += (1 << cur);
	return ans;
}
int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << split(a, 30) << endl;
}