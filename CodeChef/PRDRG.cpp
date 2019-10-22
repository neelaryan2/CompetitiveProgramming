#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, x, y;
    cin >> t;

    int n[t];

    for (int i = 0; i < t; i++)
        cin >> n[i];

    for (int i = 0; i < t; i++)
    {
        x = 1; y = 2;
        for (int j = 1; j < n[i]; j++)
        {
            y = y * 2;
            if (j % 2 == 1) x = 2 * x - 1;
            if (j % 2 == 0) x = 2 * x + 1;
        }
        cout << x << " " << y << " ";
    }
}
