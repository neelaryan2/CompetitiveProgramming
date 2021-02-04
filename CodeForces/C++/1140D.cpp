#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se seond
#define all(v) (v).begin(),(v).end()
#define lb lower_bound
#define ub upper_bound

using ll = long long;
using pii = pair<int, int>;

const int k = 5;

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ll n; cin >> n;
	ll ans = n * (n * n - 1);
	ans = (ans / 3) - 2;
	cout << ans << endl;
}