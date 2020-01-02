#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s) {
    string yes = "YES", no = "NO";
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[')
            st.push(c);
        else if (c == ')' && !st.empty() && st.top() == '(')
            st.pop();
        else if (c == '}' && !st.empty() && st.top() == '{')
            st.pop();
        else if (c == ']' && !st.empty() && st.top() == '[')
            st.pop();
        else return no;
    }
    return st.empty() ? yes : no;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
