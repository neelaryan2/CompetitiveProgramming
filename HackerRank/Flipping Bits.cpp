#include <bits/stdc++.h>

using namespace std;

// Complete the flippingBits function below.
long flippingBits(long n) {
    const int bits = 32; long ans = 0;
    vector<bool> v(bits, 0);
    for (int i = bits - 1; n; i--, n >>= 1)
        v[i] = (n & 1);
    for (int i = 0; i < bits; i++)
        ans = (ans << 1) + !v[i];
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        long n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        long result = flippingBits(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
