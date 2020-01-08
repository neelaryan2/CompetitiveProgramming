/*================= *\
|  ID : aman__guta__ |
|      LANG: C++     |
\*==================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mk make_pair
#define fs first
#define sc second 
#define mod 1000000007
#define JOKER ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;

main()
{
    JOKER
    int n,k;
    cin>>n>>k;
    string a[n];
    map <string,int> s;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        s[a[i]]=1;
    }
    int ans=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i!=j)
            {
                string s1="";
                for(int i1=0; i1<k; i1++)
                {
                    if(a[i][i1]=='S' && a[j][i1]=='S')s1+='S';
                    if(a[i][i1]=='S' && a[j][i1]=='T')s1+='E';
                    if(a[i][i1]=='S' && a[j][i1]=='E')s1+='T';
                    if(a[i][i1]=='E' && a[j][i1]=='S')s1+='T';
                    if(a[i][i1]=='E' && a[j][i1]=='T')s1+='S';
                    if(a[i][i1]=='E' && a[j][i1]=='E')s1+='E';
                    if(a[i][i1]=='T' && a[j][i1]=='T')s1+='T';
                    if(a[i][i1]=='T' && a[j][i1]=='S')s1+='E';
                    if(a[i][i1]=='T' && a[j][i1]=='E')s1+='S';
                }
                if(s.find(s1)!=s.end())ans++;
            }
            // cout<<ans<<endl;
        }
    }
    cout<<ans/6;
    cerr<<"Time elapsed : "<<clock()*1000.0/CLOCKS_PER_SEC<<"ms"<<'\n'; 
    return 0;
}