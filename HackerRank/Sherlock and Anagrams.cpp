#include <bits/stdc++.h>

using namespace std;

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
    long long ans = 0;
    int n = s.size();
    map<string, int> mp;
    for (int len = 1; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            string st = s.substr(i, len);
            sort(st.begin(), st.end());
            if (mp.find(st) == mp.end())
                mp[st] = 0;
            mp[st]++;
        }
    }
    for (auto it = mp.begin(); it != mp.end(); it++) {
        n = it->second;
        ans += (1LL * n * (n - 1)) / 2;
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
