#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define mp make_pair
#define fi first
#define se second
const int mxn = 1e6 + 10;
vector<int> cnt(mxn, 0);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		cnt[a]++;
	}
	int ans = 0, sum = 0;
	int l = 1, r = 0;
	while (l < mxn) {
		while (r + 1 < mxn && r - l < m - 1) {
			sum += cnt[++r];
			if (sum == k) {
				cnt[r]--;
				sum--, ans++;
			}
		}
		sum -= cnt[l++];
	}
	cout << ans << endl;
}