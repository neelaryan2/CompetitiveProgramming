#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld; 
typedef double db; 
typedef string str; 
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl; 
typedef pair<ld,ld> pd; 
 
typedef vector<int> vi; 
typedef vector<ll> vl;
typedef vector<ld> vd; 
typedef vector<str> vs; 
typedef vector<pl> vpl; 

#define forn(i, a, b) for (int i = a; i < b; i++)
#define rfor(i, b, a) for (int i = b; i > a; i--)
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n - 1; i >= 0; i--)
#define forv(i, v) for (auto i : v)

#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()
#define rall(v) v.rbegin(), v.rend() 

#define max3(a, b, c) max(a, max(b, c))
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define min3(a, b, c) min(a, min(b, c))
#define min4(a, b, c, d) min(min(a, b), min(c, d))

#define popcnt __builtin_popcount
#define popcntll __builtin_popcountll
#define ctz __builtin_ctz
#define ctzll __builtin_ctzll
#define gcd __gcd

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

#define Set(n, i) n = n | (1LL << i)
#define Reset(n, i) n = n & ~(1LL << i)
#define Test(n, i) (n >> i & 1LL)
#define par(n) n & 1LL

template <typename T>
inline T maxim(T v) { return v;}
template <typename T, typename... Types>
inline T maxim(T v, Types... u) {return max(v, maxim(u...));}

template <typename T>
inline T minim(T v) { return v;}
template <typename T, typename... Types>
inline T minim(T v, Types... u) {return min(v, minim(u...));}

template <typename T>
inline void print(T v) { cout << v << "\n";}
template <typename T, typename... Types>
inline void print(T v, Types... u) {cout << v << " " ; print(u...) ;}

const int N = 1e9 + 1;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n, k, shift = 0;
	cin >> n >> k;
	if (k * (k - 1) < n) {print("NO"); return 0;}
	print("YES");
	rep(i, n) {
		if (i % k == 0) shift++;
		print(i % k + 1, (shift + i % k) % k + 1);
	}
	return 0;
}