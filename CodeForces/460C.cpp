#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m, w;
vector<int> arr;
bool check(int lvl) {
	vector<int> added(n, 0);
	int sum = 0, cnt = 0, tot = 0;
	for (int i = 0; i < n; i++) {
		if (cnt == w) sum -= added[i - w];
		else cnt++;
		if (arr[i] + sum < lvl) {
			added[i] = lvl - arr[i] - sum;
			sum = lvl - arr[i];
		}
		tot += added[i];
		if (tot > m) return false;
	}
	return  (tot <= m);
}
int main() {
	cin >> n >> m >> w;
	arr.resize(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int lo = 1, hi = 2e9, mid;
	while (lo < hi - 1) {
		mid = lo + (hi - lo) / 2;
		if (check(mid)) lo = mid;
		else hi = mid;
	}
	cout << lo << endl;
}