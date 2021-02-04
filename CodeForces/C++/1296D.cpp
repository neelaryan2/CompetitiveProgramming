#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
using pii = pair<int, int>;
const int inf = 1e6;

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, a, b, k, pts = 0;
	cin >> n >> a >> b >> k;
	vector<int> h;
	for (int i = 0; i < n; i++) {
		int curr; cin >> curr;
		curr %= a + b;
		if (curr == 0) curr = a + b;
		if (curr <= a) pts++;
		else h.emplace_back(curr);
	}
	sort(h.begin(), h.end());
	for (int i : h) {
		k -= (i - 1) / a;
		if (k >= 0) pts++;
		else break;
	}
	cout << pts << endl;
}