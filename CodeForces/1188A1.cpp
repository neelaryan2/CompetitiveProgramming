#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	vector<int> deg(n, 0);
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		deg[--v]++;
		deg[--u]++;
	}
	for (int i = 0; i < n; i++)
		if (deg[i] == 2)
			return puts("NO"), 0;
	puts("YES");
}