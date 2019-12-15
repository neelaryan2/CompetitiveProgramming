#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 200005;
int a[N], ans[N];
vector<int> adj[N];
queue<int> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)	{
		cin >> a[i];
		ans[i] = - 1;
		if (i + a[i] < n) adj[i + a[i]].push_back(i);
		if (i - a[i] >= 0) adj[i - a[i]].push_back(i);
	}
	for (int i = 0; i < n; i++) {
		for (int j : adj[i])
			if ((a[i] + a[j]) % 2) {
				ans[j] = 1;
				q.push(j);
			}
	}
	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (int u : adj[v]) {
			if (ans[u] != -1) continue;
			ans[u] = ans[v] + 1;
			q.push(u);
		}
	}
	for (int i = 0; i < n; ++i)
		cout << ans[i] << " ";
	cout << endl;

	return 0;
}