#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define ll long long
const ll MOD = 998244353;

int main()
{
    ll n;
    cin >> n;
    ll conx[n + 1], cony[n + 1], fact[n + 1];
    pair<ll, ll> a[n];

    for (ll i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y;

    fact[0] = 1;
    for (ll i = 0; i < n; i++)
        fact[i + 1] = ((i + 1) * fact[i]) % MOD;

    for (ll i = 1; i <= n; i++)
    {
        conx[i] = 0;
        cony[i] = 0;
    }
    for (ll i = 0; i < n; i++)
    {
        conx[a[i].x]++;
        cony[a[i].y]++;
    }
    sort(a, a + n);
    ll count[n];
    for (ll i = 0; i < n; i++)
        count[i] = 1;
    ll index = 0;
    for (ll i = 0; i < n - 1; i++)
    {
        if (a[i].x == a[i + 1].x && a[i].y == a[i + 1].y)
            count[index]++;
        else index++;
    }
    bool check = true;
    ll yin[n];
    for (ll i = 0; i < n; i++)
        yin[i] = a[i].y;
    sort(yin, yin + n);
    for (ll i = 0; i < n; i++)
        if (a[i].y != yin[i])
            check = false;
    ll tot = check ? 1 : 0;
    for (ll i = 0; i <= index; i++)
        tot = (tot * fact[count[i]]) % MOD;
    ll x = 1, y = 1;

    for (ll i = 1; i <= n; i++)
    {
        x = (x * fact[conx[i]]) % MOD;
        y = (y * fact[cony[i]]) % MOD;
    }
    ll ans = (fact[n] - x - y + tot) % MOD;
    if (ans < 0) ans += MOD;
    cout << ans << endl;
}