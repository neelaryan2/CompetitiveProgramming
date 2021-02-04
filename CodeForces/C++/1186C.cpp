#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    int len = b.length();
    int cnt_a = 0, cnt_b = 0, ans = 0;
    for (int i = 0; i < len; i++) {
        if (a[i] == '1')
            cnt_a++;
        if (b[i] == '1')
            cnt_b++;
    }
    if ((cnt_a - cnt_b) % 2 == 0) ans++;
    for (int i = 0; i < a.length() - b.length(); i++) {
        if (a[i] == '1')
            cnt_a--;
        if (a[i + len] == '1')
            cnt_a++;
        if ((cnt_a - cnt_b) % 2 == 0) ans++;
    }
    cout << ans << endl;
}