#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, n, curr;
	cin >> t;
	while (t--) {
		cin >> n; curr = 1;
		if (n == 1) {
			printf("1\n1 1\n");
			continue;
		}
		printf ("%d\n", n / 2);
		if (n % 2) {
			printf ("3 1 2 3\n");
			n -= 3; curr = 4;
		}
		while (n) {
			printf ("2 %d %d\n", curr, curr + 1);
			curr += 2; n -= 2;
		}
	}
}