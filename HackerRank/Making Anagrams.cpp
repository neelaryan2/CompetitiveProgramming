#include <bits/stdc++.h>
using namespace std;

int makeAnagram(string a, string b) {
    int alph = 26, ans = 0;
    vector<int> cnt(alph, 0);
    for (char c : a) cnt[c - 'a']++;
    for (char c : b) cnt[c - 'a']--;
    for (int i = 0; i < alph; i++)
        ans += abs(cnt[i]);
    return ans;
}
int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    string a;
    getline(cin, a);
    string b;
    getline(cin, b);
    int res = makeAnagram(a, b);
    fout << res << "\n";
    fout.close();
    return 0;
}
