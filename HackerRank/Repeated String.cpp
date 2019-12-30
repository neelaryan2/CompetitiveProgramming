#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    long long ans = 0, cnt = 0;
    for (char c : s) {
        if (c == 'a')
            cnt++;
    }
    int k = s.size();
    ans = (n / k) * cnt; cnt = 0;
    for (int i = 0; i < n % k; i++) {
        if (s[i] == 'a')
            cnt++;
    }
    return ans + cnt;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
