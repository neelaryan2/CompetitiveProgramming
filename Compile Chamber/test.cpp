#include <cstdio>
int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    long long s, r = 2e18;
    for (int l = 1; l < 2e3; ++l) {
        s = 0;
        for (int i = 0; i < n; ++i) {
            s += a[i];
            if (i < l) continue;
            s -= a[i - l];
            r = min(r, s * s + l * l);
        }
    }
    printf("%lld", r);
}

