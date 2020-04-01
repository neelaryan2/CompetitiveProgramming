#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 15000000 + 5;
int cnt[N], least[N];
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	vector<int> arr(n);
	int g = 0;
	for (int i = 2; i < N; i += 2)
		least[i] = 2;
	for (int i = 3; i < N; i += 2) {
		if (least[i]) continue;
		least[i] = i;
		if (N / i < i) continue;
		int j = i * i;
		while (j < N) least[j] = i, j += i;
	}
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		arr[i] = a;
		g = __gcd(g, a);
	}
	int tot = 0;
	for (int i = 0; i < n; i++) {
		int tmp = arr[i] / g;
		if (tmp == 1) tot++;
		while (tmp > 1) {
			int p = least[tmp];
			while (tmp % p == 0) tmp /= p;
			cnt[p]++;
		}
	}
	if (tot == n)  {
		cout << -1 << endl;
		return 0;
	}
	int mx = *max_element(cnt + 2, cnt + N);
	cout << n - mx << endl;
}
