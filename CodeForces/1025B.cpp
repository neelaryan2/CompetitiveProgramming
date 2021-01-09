#include<bits/stdc++.h>
using namespace std;

list<int> l;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, a, b;
	cin >> n >> a >> b;
	for (int i = 2; i * i <= max(a, b); i++) {
		if (a % i && b % i) continue;
		l.push_back(i);
		while (a % i == 0) a /= i;
		while (b % i == 0) b /= i;
	}
	if (a != 1) l.push_back(a);
	if (b != 1 && a != b) l.push_back(b);
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		if (l.empty()) continue;
		for (auto it = l.begin(); it != l.end(); it++)
			if (a % (*it) && b % (*it))
				it = l.erase(it), it--;
	}
	if (l.empty()) cout << "-1\n";
	else cout << *l.rbegin() << "\n";
}