#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 200005;
int a[N];
bool keyb[26];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	char temp;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		a[i] = temp - 'a';
	}
	for (int i = 0; i < 26; i++)
		keyb[i] = false;
	for (int i = 0; i < k; i++) {
		cin >> temp;
		keyb[temp - 'a'] = true;
	}
	ll ans = 0;
	ll cou = 0;
	for (int i = 0; i < n; i++) {
		cou++;
		if (!keyb[a[i]]) {
			ans += (cou * (cou - 1)) / 2;
			cou = 0;
		}
	}
	ans += (cou * (cou + 1)) / 2;

	cout << ans << endl;
	return 0;
}