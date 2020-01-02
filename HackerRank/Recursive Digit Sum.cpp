#include <bits/stdc++.h>
using namespace std;

int main() {
	string sn; int k, sum = 0;
	cin >> sn >> k;
	long long n = 0;
	for (char c : sn) n += (c - '0');
	for (n *= k; n > 9; n = sum)
		for (sum = 0; n != 0; n /= 10)
			sum += n % 10;
	cout << n << "\n";
}