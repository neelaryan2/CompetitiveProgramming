#include <bits/stdc++.h>
using namespace std;
// Complete the candies function below.
long candies(int n, vector<int> arr) {
    const int inf = 1e6;
    queue<pair<int, int>> q;
    vector<bool> vis(n + 2, false);
    vector<int> ans(n + 2, 0);
    vector<int> a(n + 2);
    for (int i = 1; i <= n; i++) a[i] = arr[i - 1];
    vis[0] = vis[n + 1] = true;
    a[0] = a[n + 1] = inf;
    for (int i = 1; i <= n; i++) {
        if (a[i - 1] >= a[i] && a[i + 1] >= a[i])
            q.push({1, i});
    }
    while (!q.empty()) {
        pair<int, int> p = q.front(); q.pop();
        int f = p.first, s = p.second;
        ans[s] = max(ans[s], f);
        if (vis[s]) continue;
        vis[s] = true;
        if (a[s + 1] > a[s]) q.push({f + 1, s + 1});
        if (a[s - 1] > a[s]) q.push({f + 1, s - 1});
    }
    long cnt = 0;
    for (int i = 1; i <= n; i++) cnt += ans[i];
    return cnt;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    long result = candies(n, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
