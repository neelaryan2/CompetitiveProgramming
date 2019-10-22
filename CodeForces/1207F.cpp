#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int decomp = 500;
int main()
{
    ll q, typ, x, y, sum;
    cin >> q;
    ll dp[decomp][decomp];
    for (int i = 0; i < decomp; i++)
        for (int j = 0; j < decomp; j++)
            dp[i][j] = 0;
    ll a[500001];
    vector<ll> ans;
    for (int i = 0; i < 500001; i++)
        a[i] = 0;
    while (q--)
    {
        cin >> typ >> x >> y;
        if (typ == 1)
        {
            for (int i = 1; i < decomp; i++)
                dp[i][x % i] += y;
            a[x] += y;
        }
        else
        {
            sum = 0;
            if (x < decomp)
                sum += dp[x][y];
            else
            {
                for (int i = y; i < 500001; i += x)
                    sum += a[i];
            }
            ans.push_back(sum);
        }
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    return 0;
}