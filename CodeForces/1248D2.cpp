#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> a;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	string s;
	cin >> n >> s;
	if (s[0] == '(') a.push_back(1);
	else a.push_back(-1);
	for (int i = 1; i < n; i++) {
		if (s[i] == '(') a.push_back(a.back() + 1);
		else a.push_back(a.back() - 1);
	}
	if (a.back()) {
		cout << 0 << endl << 1 << " " << 1 << endl;
		return 0;
	}
	int mini = 0, total = 0;
	for (int i = 0; i < n; i++)
		if (a[i] < mini)
			mini = a[i];
	for (int i = 0; i < n; i++)
		if (a[i] == mini)
			total++;
	int l1, r1, l2, r2;
	for (int i = 0; i < n; i++)
		if (a[i] == mini)
		{l1 = i; break;}
	for (int i = 0; i < n; i++)
		if (a[i] == mini + 2)
		{l2 = i; break;}
	for (int i = n - 1; i >= 0; i--)
		if (a[i] == mini)
		{r1 = i; break;}
	for (int i = n - 1; i >= 0; i--)
		if (a[i] == mini + 2)
		{r2 = i; break;}
	int l = l2, r = r2, ans1 = 0, ans2 = 0;
	while (l != r) {
		
	}
	if (s[l1] == ')' && s[r1] == '(') {
		for (int i = 0; i < n; i++) {
			if (a[i] == mini + 2 && i < l1) ans2++;
			else if (a[i] == mini && i < r1) ans2++;
			else if (a[i] == mini + 2) ans2++;
		}
	} else ans2 = 0;

	cout << ans1 << " " << ans2 << endl;
}
