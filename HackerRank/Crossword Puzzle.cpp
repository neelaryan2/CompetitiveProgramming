#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define vs vector<string>
const int maxn = 10;

vs crossword(maxn), words(1, "");
bool solve();
bool try_place (int i, int j, bool r) {
    string word = words.back();
    if ((r ? j : i) + word.size() > maxn) return false;
    for (int k = 0; k < word.size(); ++k) {
        if (crossword[r ? i : i + k][r ? j + k : j] != '-'
                && crossword[r ? i : i + k][r ? j + k : j] != word[k])
            return false;
    }
    vs crossword_copy = crossword;
    for (int k = 0; k < word.size(); ++k)
        crossword[r ? i : i + k][r ? j + k : j] = word[k];
    words.pop_back();
    bool success = solve();
    words.eb(word);
    if (!success) crossword = crossword_copy;
    return success;
}
bool solve() {
    if (words.size() == 0) return true;
    for (int i = 0; i < maxn; ++i) {
        for (int j = 0; j < maxn; ++j) {
            if (try_place(i, j, 1)) return true;
            if (try_place(i, j, 0)) return true;
        }
    }
    return false;
}
int main() {
    for (int i = 0; i < maxn; i++)
        cin >> crossword[i];
    string wordstr; cin >> wordstr;
    for (char c : wordstr)
        if (c == ';') words.eb("");
        else words.back() += c;
    bool c = solve();
    for (int i = 0; i < maxn; i++)
        cout << crossword[i] << endl;
}
