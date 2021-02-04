#include<bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin >> s;

    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[0] == s[i + 1])
        {swap(s[0], s[i]); cout << 1 << " ";}
        else cout << 0 << " ";
    }

    if (s[s.size() - 1] == 'b')
        cout << 0 << " ";
    else cout << 1 << " ";
}