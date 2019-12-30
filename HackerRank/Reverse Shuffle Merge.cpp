#include <bits/stdc++.h>

using namespace std;
void printStack(stack<int> st) {
    while (!st.empty()) cout << char(st.top() + 'a'), st.pop();
    cout << endl;
}
// Complete the reverseShuffleMerge function below.
string reverseShuffleMerge(string s) {
    int n = s.size();
    string ans = "";
    stack<int> st;

    vector<int> need(26, 0);
    for (char c : s) need[c - 'a']++;
    vector<int> remain = need;
    for (int i = 0; i < 26; i++) need[i] /= 2;

    for (int i = n - 1; i >= 0; i--) {
        int c = s[i] - 'a'; remain[c]--;
        cout << i << " "; printStack(st);
        if (need[c] == 0) continue;
        else need[c]--;
        while (!st.empty() &&
                st.top() > c &&
                remain[st.top()] > need[st.top()])
            need[st.top()]++, st.pop();
        st.push(c);
    }

    while (!st.empty()) ans = char(st.top() + 'a') + ans, st.pop();
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    string s;
    cin >> s;

    string result = reverseShuffleMerge(s);

    cout << result << "\n";
#ifdef LOCAL
    // cout << "\nTime Elapsed: " << runtime() << " sec\n";
#endif
    return 0;
}
