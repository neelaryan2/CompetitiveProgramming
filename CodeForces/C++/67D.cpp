#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	int pos[n], arr[n];
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		pos[a - 1] = n - i - 1;
	}
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		arr[i] = pos[a - 1];
	}
	set<int> s;
	for (int i = 0; i < n; i++) {
		int c = arr[i];
		auto it = s.lower_bound(c);
		if (it != s.end()) s.erase(it);
		s.insert(c);
	}
	cout << s.size() << endl;
}