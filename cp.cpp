// only pain :(
#include <bits/stdc++.h>
#define mod 1000000007
#define lli int
#define fo(i,n) for(i=0;i<n;i++)
using namespace std;
lli t,i,l,n,k,j,m,p,ans=0;
string s;
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); 
    //cout.tie(NULL); 
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>t;
    //t=1;
    for(j=0;j<t;j++)
    {
        cout<<"Case #"<<j+1<<": ";
        ans=0;
        cin>>s>>n;
        vector<vector<lli>> a(26,vector<lli>(s.size()+2));
        fo(i,s.size())
        {
        for(k=0;k<26;k++)
        a[k][i+1]=a[k][i]+(s[i]-'a'==k);
        }
        while(n--)
        {
            lli k1,k2,p1=0,p2=0;
            cin>>k1>>k2;
            if((k2-k1)%2)
            continue;
            fo(i,26)
            {
                if((a[i][k1+(k2-k1+1)/2]-a[i][k1-1])-(a[i][k2]-a[i][k1+(k2-k1+1)/2])==0)
                p1++;
                if((a[i][k1+(k2-k1+1)/2-1]-a[i][k1-1])-(a[i][k2]-a[i][k1+(k2-k1+1)/2-1])==0)
                p2++;
            }
            if(p1==25||p2==25)
            ans++;
        }
        cout<<ans;
        cout<<"\n";
    }
return 0;
}