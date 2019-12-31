#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
#define vi vector<int>
// Complete the countInversions function below.
long merge(vi& arr, int s, int m, int e) {
    long ans = 0; vi l, r; int i, j, st = s;
    for (i = s; i < m; i++) l.emplace_back(arr[i]);
    for (j = m; j < e; j++) r.emplace_back(arr[j]);
    m = l.size(); e = r.size();
    for (i = 0, j = 0; i < m && j < e;) {
        if (l[i] > r[j]) arr[st++] = r[j++], ans += m - i;
        else arr[st++] = l[i++];
    }
    while (i < m) arr[st++] = l[i++];
    while (j < e) arr[st++] = r[j++];
    return ans;
}
long mergesort(vi& arr, int s, int e) {
    if (s >= e - 1) return 0;
    int m = (s + e) / 2; long ans = 0;
    ans += mergesort(arr, s, m);
    ans += mergesort(arr, m, e);
    ans += merge(arr, s, m, e);
    return ans;
}
long countInversions(vi arr) {
    return mergesort(arr, 0, arr.size());
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        long result = countInversions(arr);

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
