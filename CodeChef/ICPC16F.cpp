#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, m, a, b;
		cin >> n >> m >> a >> b;
		if (m < n * a || m > n * b)
		{cout << -1 << endl; continue;}
		int k = m / n;
		m -= k * n;
		for (int i = 1; i <= n; i++)
			for (int j = i; j < i + k; j++)
				cout << i << " " << j % n + 1 << endl;
		for (int i = 1; i <= m; i++)
			cout << i << " " << (i + k) % n + 1 << endl;
	}
	return 0;
}