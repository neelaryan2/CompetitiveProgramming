#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int b, p, f, h, c;
        cin >> b >> p >> f >> h >> c;
        b /= 2;
        if (p + f <= b)
        {
            cout << p*h + f*c << endl;
            continue;
        }
        if (!b)
        {
            cout << 0 << endl;
            continue;
        }
        if (h > c)
        {
            if (b <= p)
            {
                cout << b*h << endl;
            }
            else
                cout << p*h + (b - p)*c << endl;
        }
        if (h <= c)
        {
            if (b <= f)
            {
                cout << b*c << endl;
            }
            else
                cout << f*c + (b - f)*h << endl;
        }
    }
}