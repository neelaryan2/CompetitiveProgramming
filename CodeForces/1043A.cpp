#include<bits/stdc++.h>
using namespace std;

int main() {

    int n, maxi = 0, sum = 0;
    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        maxi = max(maxi, a[i]);
        sum += a[i];
    }
    double k = sum * 2 / n;
    sum = static_cast<int>(k);

    cout << max(sum + 1, maxi);
    return 0;
}