#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, x, k, sum;
	cin >> t;
	while (t--) {
		cin >> x >> k; sum = 0;
		for (int i = 2; i * i <= x; i++) {
			if (x % i) continue;
			while (x % i == 0) x /= i, sum++;
		}
		if (x != 1) sum++;
		puts((sum >= k) ? "1" : "0");
	}
}