include<bits/stdc++.h>
using namespace std;
struct query {
	int t;
	int l;
	int r;
};
int main() {
	int n, m;
	cin >> n >> m;
	int a[n];
	query q[m];
	int diff[n - 1];
	for (int i = 0; i < n - 1; i++)
		diff[i] = -1;
	a[0] = n;
	for (int i = 0; i < m; i++) {
		cin >> q[i].t >> q[i].l >> q[i].r;
		if (q[i].t) {
			for (int j = q[i].l - 1; j < q[i].r - 1; j++)
				diff[j] = 0;
		}
	}
	for (int i = 0; i < m; i++) {
		if (!q[i].t) {
			bool check = false;
			for (int j = q[i].l - 1; j < q[i].r - 1; j++)
				if (diff[j] < 0)
					check = true;
			if (!check) {
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	for (int i = 0; i < n - 1; i++)
		a[i + 1] = a[i] + diff[i];
	cout << "YES" << endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}