#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n;
    int a[n];
    int maxa, maxb;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    int b[m];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    maxa = a[0];
    maxb = b[0];
    for (int i = 1; i < n; i++)
        maxa = max(maxa, a[i]);
    for (int i = 1; i < m; i++)
        maxb = max(maxb, b[i]);
    cout << maxa << " " << maxb << endl;
}

