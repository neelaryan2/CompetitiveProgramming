#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> v;

int main() {
	int n, temp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back({temp, i});
	}
	sort(v.begin(), v.end());
	// for (int i = 0; i < n; i++)
	// 	cout << v[i].first << " ";
	// cout << endl;
	int team = 1, ind = 0, res = 0;
	int ans[n];
	for (int i = 0; i + 5 < n; i++) {
		int d1 = v[i + 3].first - v[i + 2].first;
		int d2 = v[i + 4].first - v[i + 3].first;
		int d3 = v[i + 5].first - v[i + 4].first;
		int dmax = max(d1, max(d2, d3));
		ans[v[i].second] = team;
		ans[v[i + 1].second] = team;
		ans[v[i + 2].second] = team;
		if (dmax == d1) {
			team++;
			res += v[i + 2].first - v[i].first;
			i += 2;
			cout << res << "  adsad" << endl;
		}
		else if (dmax == d2) {
			ans[v[i + 3].second] = team;
			team++;
			res += v[i + 3].first - v[i].first;
			i += 3;
		}
		else {
			ans[v[i + 3].second] = team;
			ans[v[i + 4].second] = team;
			team++;
			res += v[i + 4].first - v[i].first;
			i += 4;
		}
		ind = i+1;
	}
	if (ind != n) {
		res -= v[ind].first;
		while (ind < n) {
			ans[v[ind].second] = team;
			ind++;
		}
		res += v[n - 1].first;
	}
	cout << res << " " << team << endl;
	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";
	cout << endl;
}