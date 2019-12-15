#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 200005;
int a[N], dp1[N], dp2[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	dp2[0] = dp1[n - 1] = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] > a[i - 1])
			dp2[i] = dp2[i - 1] + 1;
		else dp2[i] = 1;
	}
	for (int i = n - 2; i >= 0; i--) {
		if (a[i] < a[i + 1])
			dp1[i] = dp1[i + 1] + 1;
		else dp1[i] = 1;
	}
	int ans = -1;
	for (int i = 0; i < n; ++i)
		ans = max(ans, dp1[i]);

	for (int i = 1; i < n - 1; i++) {
		if (a[i - 1] < a[i + 1]) {
			ans = max(ans, dp2[i - 1] + dp1[i + 1]);
		}
	}
	cout << ans << endl;
	return 0;
}