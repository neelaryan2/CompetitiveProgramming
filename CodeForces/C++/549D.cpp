#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	int a[n][m], ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			char c; cin >> c;
			a[i][j] = (c == 'W') ? 1 : -1;
		}
	for (int i = n; i > 0; i--)
		for (int j = m; j > 0; j--) {
			int curr = a[i - 1][j - 1];
			if (curr == 0) continue; 
			else ans++;
			for (int u = 0; u < i; u++)
				for (int v = 0; v < j; v++)
					a[u][v] -= curr;
		}
	cout << ans << endl;
}