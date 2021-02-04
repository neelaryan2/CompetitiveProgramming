#include<bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int l[n], r[n];
	long long ans = n;
	for (int i = 0; i < n; i++)
		cin >> l[i] >> r[i];
	sort(l, l + n); sort(r, r + n);
	for (int i = 0; i < n; i++)
		ans += max(l[i], r[i]);
	cout << ans << endl;
}