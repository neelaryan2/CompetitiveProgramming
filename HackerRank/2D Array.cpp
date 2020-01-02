#include <bits/stdc++.h>
using namespace std;

const int maxn = 6, h = 3;
int hourglassSum(vector<vector<int>> arr) {
    int ans = -500, sum = 0;
    for (int l = 0; l + h <= maxn; l++)
        for (int r = 0; r + h <= maxn; r++) {
            sum = 0;
            for (int i = 0; i < h; i++)
                for (int j = 0; j < h; j++)
                    sum += arr[i + l][j + r];
            sum -= (arr[l + 1][r] + arr[l + 1][r + h - 1]);
            ans = max(ans, sum);
        }
    return ans;
}
int main() {
    vector<vector<int>> arr(maxn);
    for (int i = 0; i < maxn; i++) {
        arr[i].resize(maxn);
        for (int j = 0; j < maxn; j++)
            cin >> arr[i][j];
    }
    int result = hourglassSum(arr);
    cout << result << "\n";
}
