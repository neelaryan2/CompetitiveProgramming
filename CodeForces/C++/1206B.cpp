#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n, counts = 0, ans = 0, counts0 = 0;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] < 0)
        {
            counts++;
            ans += (-1) - a[i];
        }
        else if (a[i] == 0)
            counts0++;
        else ans += a[i] - 1;
    }
    if (counts % 2 && !counts0 ) cout << ans + 2 << endl;
    else cout << ans + counts0 << endl;
}