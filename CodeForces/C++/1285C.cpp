#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ll x, a; cin >> x;
	for (ll i = sqrt(x) + 1; i > 0; i--) {
		if (x % i) continue;
		if (__gcd(i, x / i) != 1) continue;
		a = i; break;
	}
	cout << x / a << " " << a << endl;
}