#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se seond
#define all(v) (v).begin(),(v).end()
#define lb lower_bound
#define ub upper_bound

using ll = long long;
using pii = pair<int, int>;
string s;
bool check(int k) {
	for (int i = 0; i < k; i++)
		for (int j = i; j < s.size(); j += k)
			if (s[i] != s[j]) return false;
	return true;
}
int main() {
	string s1, s2;
	cin >> s1 >> s2;
	int l1 = s1.size(), l2 = s2.size();
	s = s1 + s2; int ans = 0;
	for (int i = 1; i <= min(l1, l2); i++) {
		if (l1 % i || l2 % i) continue;
		if (check(i)) ans++;
	}
	cout << ans << endl;
}