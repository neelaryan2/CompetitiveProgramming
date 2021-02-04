#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int n, x;
    cin >> n >> x;
    long long int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    set<long long int>s;
    pair<long long int, long long int>a[x + 1];
    for (long long int i = 0; i <= x; i++) {
        a[i] = make_pair(-1, -1);
    }
    long long int maxi = 0;

    for (long long int i = 0; i < n; i++) {
        if (maxi <= arr[i]) {
            s.insert(arr[i]);
            maxi = arr[i];
            continue;
        }
        else if (maxi > arr[i]) {
            s.insert(arr[i]);
            a[arr[i]].second = maxi;
            auto it = s.upper_bound(arr[i]);
            a[arr[i]].first = *it;
            continue;
        }
    }

    long long int pre1[x + 1];

    pre1[0] = 1000000000;
    for (long long int i = 1; i <= x; i++) {

        if (a[i].first == -1) {
            pre1[i] = pre1[i - 1];
            continue;
        }

        pre1[i] = min(pre1[i - 1], a[i].first);
    }

    long long int final = -1;
    for (int i = x; i > 0; i--) {

        if (a[i].first != -1) {
            final = i;

            break;
        }
    }

    if (final == -1) {
        cout << (x * (x + 1)) / 2;
        return 0;
    }

    long long int pre2[x + 1];
    pre2[0] = 0;
    for (long long int i = 1; i <= x; i++) {
        if (a[i].first == -1) {
            pre2[i] = pre2[i - 1];

        }
        else {
            pre2[i] = max(pre2[i - 1], a[i].second);
        }

    }


    long long int ans = 0;
    for (long long int i = 1; i <= x; i++) {
        if (pre1[i - 1] < i) {
            break;
        }
        else {
            long long int r = pre2[i - 1];
            r = max(i, r);
            if (i < final) {
                r = max(r, final);
            }
            ans = ans + (x - r + 1);
        }
    }
    cout << ans;
    return 0;
}