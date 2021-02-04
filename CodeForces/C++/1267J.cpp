#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2000005;
vector<int> a, cou;

int check(int s) {
	int sum = 0;
	for (int i = 0; i < cou.size(); i++) {
		int q = 1 + ((cou[i] - 1) / s);
		sum += q;
		if (q * (s - 1) > cou[i]) return -1;
	}
	return sum;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, n, temp, co, s, ans;
	cin >> t;
	while (t--) {
		a.clear(); cou.clear();
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			a.push_back(temp);
		}
		sort(a.begin(), a.end());
		co = 1;
		for (int i = 1; i < n; i++) {
			if (a[i] != a[i - 1]) {
				cou.push_back(co);
				co = 1;
			}
			else co++;
		}
		cou.push_back(co);
		sort(cou.begin(), cou.end());
		s = cou[0] + 1; ans = -1;
		for (; s >= 2; s--)	{
			ans = check(s);
			if (ans != -1) break;
		}
		cout << ans << endl;
	}

	return 0;
}