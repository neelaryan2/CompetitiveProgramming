#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef double db;
typedef string str;

typedef pair<int, int> pi;
typedef pair<long long, long long> pl;
typedef pair<long double, long double> pd;

typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<long double> vd;
typedef vector<string> vs;
typedef vector<pair<ll, ll>> vpl;

#define forn(i, a, b) for (int i = (a); i < (b); i++)
#define rfor(i, b, a) for (int i = (b); i > (a); i--)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repr(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forv(i, v) for (auto& (i) : (v))
#define trav(i, v) for (auto i = (v).begin(); i != (v).end(); i++)

#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define rall(v) (v).rbegin(), (v).rend()
#define pc(c) putchar(c)
// #define gc(c) getchar(c)
#define br() cout << endl

#define popcnt __builtin_popcount
#define popcntll __builtin_popcountll
#define ctz __builtin_ctz
#define ctzll __builtin_ctzll

#define fi first
#define se second
#define pb push_back
#define pf push_front
#define ef emplace_front
#define eb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define rsz resize
#define ins insert
#define endl "\n"

#define Set(n, i) n = (n) | (1LL << (i))
#define Reset(n, i) n = (n) & ~(1LL << (i))
#define Test(n, i) ((n) >> (i) & 1LL)
#define par(n) (n) & 1LL

template <typename T>
inline void pv(vector<T> v) {
    for (T x : v) cout << x << " ";
    cout << endl;
}
namespace io {
const int SIZE = (1 << 21) + 1;
char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
// getchar
#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
// print the remaining part
inline void flush () {
    fwrite (obuf, 1, oS - obuf, stdout);
    oS = obuf;
}
inline void putc (char x) { // putchar
    *oS ++ = x;
    if (oS == oT) flush ();
}
inline bool read (signed &x) { // input a signed integer
        for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1; else if (c == EOF)return 0;
    for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
    return 1;
}
inline bool read (long long &x) {
        for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1; else if (c == EOF)return 0;
    for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
    return 1;
}
inline bool read (char &x) {
    x = gc();
    return x != EOF;
}
inline bool read(char *x) {
    while ((*x = gc()) == '\n' || *x == ' ' || *x == '\r')if (*x == EOF)return 0;
    while (!(*x == '\n' || *x == ' ' || *x == '\r'))*(++x) = gc();
    *x = 0;
    return 1;
}
// inline bool read(string& x) {
//     while ((*x = gc()) == '\n' || *x == ' ' || *x == '\r')if (*x == EOF)return 0;
//     while (!(*x == '\n' || *x == ' ' || *x == '\r'))*(++x) = gc();
//     *x = 0;
//     return 1;
// }
// inline bool read(string& x) {
//     char c; x.clear(); c = gc();
//     while (c != '\n' && c != ' ' && c != '\r') {
//         cout << c << " dsfsdf" << endl;
//         if (c == EOF) return 0;
//         else x.push_back(c);
//         c = gc();
//     }
//     return 1;
// }
inline bool read() {return 1;}
template<typename A, typename ...B>
inline bool read(A &x, B &...y) {
    return read(x) && read(y...);
}
// print a signed integer
inline bool write (signed x) {
    if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
    while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
    while (qr) putc (qu[qr --]);
    return 0;
}
inline bool write (long long x) {
    if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
    while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
    while (qr) putc (qu[qr --]);
    return 0;
}
inline bool write (char x) {
    putc(x);
    return 0;
}
inline bool write (string s) {
    for (char a : s) putc(a);
    return 0;
}
inline bool write(const char *x) {
    while (*x) {putc(*x); ++x;}
    return 0;
}
inline bool write(char *x) {
    while (*x) {putc(*x); ++x;}
    return 0;
}
inline bool write() {
    return 0;
}
template<typename A, typename ...B>
inline bool write(A x, B ...y) {
    return write(x) || write(y...);
}
//no need to call flush at the end manually!
struct Flusher_ {~Flusher_() {flush();}} io_flusher_;
}
using io :: read;
using io :: putc;
using io :: write;
const int N = 1e9 + 7;
const int mod = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    char* s;
    read(s);
    // write("-1\n");
    // read(s);
    write(s, '\n');
    // read(s,t);
    // write(s," ",t,'\n');
    // cout << s << " " << t << endl;
    return 0;
}