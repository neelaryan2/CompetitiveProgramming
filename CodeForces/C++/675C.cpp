#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	int n, mx = 0; 
	cin >> n; ll sum = 0;
	map<ll, int> cnt;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		sum += a; cnt[sum]++;
		mx = max(mx, cnt[sum]);
	}
	cout << n - mx << endl;
}