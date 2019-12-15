#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1005;
int n, l, k;
char a[N * N];
char ans[N][N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> l >> k;
	for (int i = 0; i < n * l; i++)
		cin >> a[i];
	sort(a, a + n * l);
	int L = 0, ind = 0;
	char prev = a[0];
	for (int j = 0; j < l; j++) {
		for (int i = L; i < k; i++) {
			if (prev != a[ind]) {L = i; prev = a[ind];}
			ans[i][j] = a[ind++];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < l; j++) {
			if (!ans[i][j]) ans[i][j] = a[ind++];
			cout << ans[i][j];
		}
		cout << endl;
	}
	return 0;
}