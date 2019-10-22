#include<bits/stdc++.h>
using namespace std;

bool check(string t, string a, string b, int n)
{
    if (a[0] == t[0] && a[1] == t[1])
        return false;
    if (a[0] == t[1] && a[1] == t[2])
        return false;
    if (a[0] == t[2] && a[1] == t[0] && n != 1)
        return false;
    if (b[0] == t[0] && b[1] == t[1])
        return false;
    if (b[0] == t[1] && b[1] == t[2])
        return false;
    if (b[0] == t[2] && b[1] == t[0] && n != 1)
        return false;
    return true;
}
string generator(string a, string b, int n)
{
    string temp = "abc";
    if (check(temp, a, b, n)) return temp;
    else {
        while (next_permutation(temp.begin(), temp.end()))
            if (check(temp, a, b, n)) return temp;
    }
    return "";
}
int main()
{
    int n;
    string t1, t2;
    cin >> n >> t1 >> t2;
    string gen1 = generator(t1, t2, n);
    string gen2 = generator(t1, t2, 1);
    string ans = "";
    if (gen1 == "")
    {
        for (int i = 0; i < n ; i++)
            ans += gen2[0];
        for (int i = 0; i < n ; i++)
            ans += gen2[1];
        for (int i = 0; i < n ; i++)
            ans += gen2[2];
        cout << "YES" << endl;
        cout << ans << endl;
        return 0;
    }
    for (int i = 0; i < n ; i++)
        ans += gen1;
    cout << "YES" << endl;
    cout << ans << endl;
}