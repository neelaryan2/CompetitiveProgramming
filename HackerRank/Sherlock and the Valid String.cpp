#include<bits/stdc++.h>
using namespace std;

const int alph = 26;
vector<int> cnt(alph, 0);
inline bool all() {
    for (int c : cnt)
        if (c != cnt[0])
            return false;
    return true;
}
int main() {
    string s; cin >> s;
    for (char c : s) cnt[c - 'a']++;
    sort(cnt.rbegin(), cnt.rend());
    while (!cnt.back()) cnt.pop_back();
    cnt[0]--;
    if (all()) return puts("YES"), 0;
    cnt[0]++; cnt.pop_back();
    if (all()) return puts("YES"), 0;
    return puts("NO"), 0;
}