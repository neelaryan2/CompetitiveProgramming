#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll counter(ll el, ll a[], ll n)
{
    ll count = 0;
    for (ll i = 0; i < n; i++)
    {
        if (a[i] == el)
            count++;
        if (a[i] > el)
            return count;
    }
    return count;
}
int main()
{
    ll n;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    if (a[0] == a[1] && a[1] == a[2])
    {
        ll count = counter(a[0], a, n);
        cout << (count * (count - 1) * (count - 2)) / 6 << endl;
    }
    else if (a[0] != a[1] && a[1] == a[2])
    {
        ll count = counter(a[1], a, n);
        cout << (count * (count - 1)) / 2 << endl;
    }
    else
    {
        ll count = counter(a[2], a, n);
        cout << count << endl;
    }
}