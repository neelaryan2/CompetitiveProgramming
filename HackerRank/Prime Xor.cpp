#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the primeXor function below.
int primeXor(vector<int> a) {
    const int l = 3500, r = 4500;
    const int mod = 1e9 + 7;
    const int N = 1 << (1 + (int)log2(r));
    const int maxn = r - l + 2;

    int flag = 0;

    vector<int> cnt(maxn, 0);
    vector<vector<long long>> dp(2, vector<long long>(N, 0));

    for (int k : a) cnt[k - l]++;

    dp[0][0] = 1 + cnt[0] / 2;
    dp[0][l] = (1 + cnt[0]) / 2;
    for (int i = l + 1; i <= r; i++) {
        int odd = (1 + cnt[i - l]) / 2;
        int even = 1 + cnt[i - l] / 2;
        flag ^= 1;
        for (int j = 0; j < N; j++) {
            dp[flag][j] = (dp[flag ^ 1][j] * even) % mod;
            dp[flag][j] = (dp[flag][j] + dp[flag ^ 1][j ^ i] * odd) % mod;
        }
    }
    long long ways = 0;
    for (int i = 2; i < N; i++) {
        bool c = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                c = false; break;
            }
        }
        if (c) ways = (ways + dp[flag][i]) % mod;
    }
    return ways;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string a_temp_temp;
        getline(cin, a_temp_temp);

        vector<string> a_temp = split_string(a_temp_temp);

        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            int a_item = stoi(a_temp[i]);

            a[i] = a_item;
        }

        int result = primeXor(a);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
