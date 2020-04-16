#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define mp make_pair
#define fi first
#define se second
const int inf = 1e9;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, x;
	cin >> n >> x;
	vector<ll> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	if (n == 1) {
		cout << (arr[0] <= x) << endl;
		return 0;
	}
	reverse(arr.begin(), arr.end());
	for (int i = 1; i < n; i++)
		arr[i] *= i + 1;
	sort(arr.begin(), arr.end());
	for (int i = 1; i < n; i++)
		arr[i] += arr[i - 1];
	int ans = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
	cout << ans << endl;
}