#include<bits/stdc++.h>
using namespace std;
template<typename T> T gcd(T a, T b) {
	while (b) {T t = b; b = a % b; a = t;}
	return a;
}
set<long long> s;
int main() {
	#ifdef LOCAL
	    freopen("in.txt", "r", stdin);
	    freopen("out.txt", "w", stdout);
	#endif
	int n, k, a, gd = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a, gd = gcd(gd, a);
	for (int i = 0; i < k; i++)
		s.insert((1LL * gd * i) % k);
	cout << s.size() << "\n";
	for (auto it = s.begin(); it != s.end(); it++)
		cout << *it << " ";
	cout << "\n";
}