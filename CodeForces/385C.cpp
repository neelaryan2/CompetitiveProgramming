#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e7 + 10;
int least[N];
ll cnt[N];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 2; i < N; i += 2)
		least[i] = 2;
	for (int i = 3; i < N; i += 2) {
		if (least[i]) continue;
		least[i] = i;
		ll j = 1LL * i * i;
		while (j < N) least[j] = i, j += i;
	}
	for (int i = 0; i < N; i++) cnt[i] = 0;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		ll a; cin >> a;
		while (a > 1) {
			int p = least[a];
			while (a % p == 0) a /= p;
			cnt[p]++;
		}
	}
	for (int i = 1; i < N; i++)
		cnt[i] += cnt[i - 1];
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		l = min(N - 1, l);
		r = min(N - 1, r);
		cout << cnt[r] - cnt[l - 1] << endl;
	}


}