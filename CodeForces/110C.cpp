#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void disp(vector<int> a) {
	for (int i : a)
		cout << i;
	cout << endl;
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; cin >> n;
	int a1 = (2 * n) % 7;
	int a2 = 4 * ((2 * n) / 7) - n;
	if (a2 < 0) {
		cout << -1 << endl;
		return 0;
	}
	for (int i = 0; i < a1; i++) cout << 4;
	for (int i = 0; i < a2; i++) cout << 7;
}