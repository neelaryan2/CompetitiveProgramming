#include<bits/stdc++.h>
using namespace std;

int main()
{
    int ti;
    cin >> ti;
    while (ti--)
    {
        int n;
        cin >> n;

        string s[n], k[n];
        int t[n];

        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
            k[i] = s[i];
            for (int j = 0; j < s[i].size(); j++)
            {
                if (s[i][j] == 'f') s[i][j] = 'd';
                if (s[i][j] == 'k') s[i][j] = 'j';
            }
        }
        for (int i = 0; i < n; i++)
        {
            t[i] = 2;
            for (int j = 1; j < s[i].size(); j++)
                if (s[i][j] != s[i][j - 1]) t[i] += 2;
                else t[i] += 4;
        }

        int sum = 0, counts;
        for (int i = 0; i < n; i++)
        {
            counts = 0;
            for (int j = i + 1; j < n; j++)
                if (k[i] == k[j] && t[i] != 0)
                {counts++; t[j] = 0;}
            t[i] += counts * t[i] / 2;
            sum += t[i];
        }
        cout << sum << endl;
    }
}
