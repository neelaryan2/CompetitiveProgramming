#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n , m;
    cin >> n >> m;
    int k = n / 2;
    for (int i = 1; i <= k ; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d %d\n", i, j);
            printf("%d %d\n", n - i + 1, m - j + 1);
        }
    }
    k = n / 2 + ((n % 2) ? 1 : 0);
    int k2 = m / 2 + ((m % 2) ? 1 : 0);
    if (k == n / 2 + 1) {
        for (int j = 1; j <= k2; j++) {
            printf("%d %d\n", k, j);
            if (j <= m / 2)
                printf("%d %d\n", k, m - j + 1);
        }
    }
}