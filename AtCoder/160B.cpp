#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ll x; cin >> x;
  	ll ans = (x/500)*1000;
  	x %= 500;
  	ans += (x/5)*5;
  	cout << ans << endl;
}