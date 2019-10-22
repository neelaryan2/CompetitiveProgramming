#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll k;
    cin >> k;
    ll n = 1, sub = 9, rem = 0;
    while (k > n * sub) {
        k -= n * sub;
        sub *= 10;
        n++;
    }
    rem = k % n;
    k = k / n;
    ll num = pow(10, n - 1) + k - 1;
    if (!rem)
        cout << num % 10 << endl;
    else {
        num++;
        while (n > rem) {
            num /= 10;
            n--;
        }
        cout << num % 10 << endl;
    }
}