#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> cnt(2e5 + 5, 0);
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		cnt[a]++;
		if (cnt[a] <= 2) continue;
		puts("NO");
		return 0;
	}
	puts("YES");
	vector<int> a1, a2;
	for (int i = 0; i < cnt.size(); i++) {
		if (cnt[i] >= 1) a1.emplace_back(i);
		if (cnt[i] == 2) a2.emplace_back(i);
	}
	reverse(a2.begin(), a2.end());
	cout << a1.size() << endl;
	for (int i : a1) cout << i << " "; cout << endl;
	cout << a2.size() << endl;
	for (int i : a2) cout << i << " "; cout << endl;
}