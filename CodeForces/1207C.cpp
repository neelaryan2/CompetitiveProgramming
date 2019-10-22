#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define x first
#define y second
int main()
{
    ll t, temp, n, a, b, len;
    ll cost = 0, count;
    string s;
    cin >> t;
    temp = t;
    ll ans[t];
    vector<pair<bool, ll>> mod;
    while (temp--)
    {
        cin >> n >> a >> b >> s;
        cost = 0;
        count = 1;
        mod.clear();
        for (ll i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
                count++;
            else
            {
                mod.push_back(make_pair(s[i] == '1', count));
                count = 1;
            }
        }
        mod.push_back(make_pair(s[n - 1] == '1', count));
        cost += b;
        ll len = mod.size();
        if (len == 1)
            cost += mod[0].y * (a + b);
        else
        {
            count = mod[0].y;
            cost += (count + 1) * (b + a);
            for (ll i = 1; i < len - 1; i++)
            {
                count = mod[i].y;
                if (mod[i].x)
                    cost += count * (2 * b + a);
                else
                    cost += count * (a + b) + min(count * b, 2 * a + b);
            }
            count = mod[len - 1].y;
            cost += count * (b + a) + a;
        }
        ans[temp] = cost;
    }
    for (ll i = t - 1; i >= 0; i--)
        cout << ans[i] << endl;
}

