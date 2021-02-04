#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
#define vi vector<ll>
#define sz(v) int((v).size())

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		char c; cin >> c;
		a[i] = c - '0';
	}
	for (int i = 0; i < k; i++)
		for (int j = i; j < n; j += k)
			b[j] = a[i];
	bool flag = true;
	for (int i = 0; i < n; i++) {
		if (b[i] > a[i]) break;
		if (b[i] < a[i]) flag = false;
	}
	cout << n << endl;
	if (flag) { for (int i : b) cout << i; cout << endl; return 0; }
	int ind = k - 1; a[ind]++;
	while (ind > 0 && a[ind] == 10) a[ind--] = 0, a[ind]++;
	for (int i = 0; i < k; i++)
		for (int j = i; j < n; j += k)
			b[j] = a[i];
	for (int i : b) cout << i; cout << endl; return 0;
}
