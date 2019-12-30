#include <bits/stdc++.h>

using namespace std;

// Complete the abbreviation function below.
string abbreviation(string a, string b) {
    string no = "NO", yes = "YES";
    int an = a.size(), bn = b.size();
    bool dp[an][bn];
    dp[0][0] = (a[0] == b[0] || toupper(a[0]) == b[0]);
    int ind = -1;
    for (int i = 0; i < an; i++) if (isupper(a[i])) {ind = i; break;}
    if (ind == -1) {
        for (int i = 1; i < an; i++)
            if (toupper(a[i]) == b[0]) dp[i][0] = true;
            else dp[i][0] = dp[i - 1][0];
    } else {
        for (int i = 1; i < ind; i++)
            if (toupper(a[i]) == b[0]) dp[i][0] = true;
            else dp[i][0] = dp[i - 1][0];
        if (a[ind] == b[0]) dp[ind][0] = true;
        int ind2 = an;
        for (int i = ind + 1; i < an; i++) {
            if (islower(a[i])) dp[i][0] = dp[i - 1][0];
            else {ind2 = i; break;}
        }
        for (int i = ind2; i < an; i++) dp[i][0] = false;
    }
    for (int j = 1; j < bn; j++) {
        dp[0][j] = false;
    }
    for (int i = 1; i < an; i++) {
        for (int j = 1; j < bn; j++) {
            if (a[i] == b[j] && isupper(a[i])) dp[i][j] = dp[i - 1][j - 1];
            else if (a[i] != b[j] && isupper(a[i])) dp[i][j] = false;
            else if (toupper(a[i]) == b[j]) dp[i][j] = dp[i - 1][j - 1] || dp[i - 1][j];
            else dp[i][j] = dp[i - 1][j];
        }
    }
    if (dp[an - 1][bn - 1]) return yes;
    else return no;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = abbreviation(a, b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
