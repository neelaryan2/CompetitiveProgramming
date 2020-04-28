#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()

void solve(){
    string t;
    cin>>t;
    bool f=true;
    char c=t[0];
    int n=t.size();
    for(int i=1; i<n; i++){
        if(t[i]!=c) f=false;
    }
    if(f || n<=2){
        cout<<t<<'\n';
        return;
    }
    for(int i=0; i<n; i++)
        cout<<"10";
    cout<<'\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}