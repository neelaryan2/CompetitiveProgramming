#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ll t, a, b;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		cout << (b - a % b) % b << endl;
	}
}