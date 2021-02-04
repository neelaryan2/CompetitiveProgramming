#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    bool a[n][m], b[n][m];
    vector<pair<int, int>> ans;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            b[i][j] = 0;
        }

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < m - 1; j++)
        {
            if (a[i][j] && a[i + 1][j + 1] && a[i][j + 1] && a[i + 1][j])
            {
                ans.push_back(make_pair(i + 1, j + 1));
                b[i][j] = 1;
                b[i + 1][j + 1] = 1;
                b[i][j + 1] = 1;
                b[i + 1][j] = 1;
            }
        }
    for (int i = 0; i < n ; i++)
        for (int j = 0; j < m ; j++)
            if (a[i][j] != b[i][j])
            {
                cout << -1 << endl;
                return 0;
            }
    cout << ans.size() << endl;;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].first << " " << ans[i].second << endl;
}