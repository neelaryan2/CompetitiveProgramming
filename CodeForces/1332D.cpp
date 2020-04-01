#include<bits/stdc++.h>
using namespace std;

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int k; cin >> k;
	int t = (1 << 17);
	cout << "2 3\n";
	cout << t + k << " " << t << " 0\n";
	cout << k << " " << t + k << " " << k << "\n";
}