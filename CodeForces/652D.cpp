#include<bits/stdc++.h>
using namespace std;

struct segment
{
    int left;
    int right;
    int ind;
};

bool comp(segment a, segment b)
{
    return a.left < b.left;
}

int sum(int bit[], int index)
{
    int sums = 0;
    for (int i = index + 1; i > 0; i -= i & -i)
        sums += bit[i];
    return sums;
}

void update(int bit[], int index, int n)
{
    for (int i = index + 1; i <= n; i += i & -i)
        bit[i]++;
}

int main()
{
    int n, l, r;
    cin >> n;
    segment seg[n];
    for (int i = 0; i < n; i++)
    {
        cin >> l >> r;
        seg[i].left = l;
        seg[i].right = r;
        seg[i].ind = i;
    }
    int tree[n + 1], ans[n];
    for (int i = 0; i < n + 1; i++)
        tree[i] = 0;

    vector<int> endy;
    for (int i = 0; i < n; i++)
        endy.push_back(seg[i].right);

    sort(seg, seg + n, comp);
    sort(endy.begin(), endy.end());

    for (int i = n - 1; i >= 0; i--)
    {
        int index = int(lower_bound(endy.begin(), endy.end(), seg[i].right) - endy.begin());
        ans[seg[i].ind] = sum(tree, index);
        update(tree, index, n);
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << endl;
}