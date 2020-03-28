#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q, x, y; cin >> q;
	int maxx = -1, maxy = -1;
	char c; bool b;
	while (q--) {
		cin >> c >> x >> y;
		if (x > y) swap(x, y);
		if (c == '+') {
			maxx = max(maxx, x);
			maxy = max(maxy, y);
		} else {
			b = (maxx <= x) && (maxy <= y);
			puts(b ? "YES" : "NO");
		}
	}
}