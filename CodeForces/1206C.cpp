#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[2 * n];
    int maxi = 2 * n;
    int mini = 1;
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; i += 2)
    {
        if (!a[i]) a[i] = mini;
        if (!a[i + n]) a[n + i] = mini + 1;
        mini += 2;
        if (!a[i + 1]) a[i + 1] = maxi;
        if (!a[i + n + 1]) a[n + i + 1] = maxi - 1;
        maxi -= 2;
    }
    if (n % 2)
    {
        cout << "YES" << endl;
        for (int i = 0; i < 2 * n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
    else
        cout << "NO" << endl;
}