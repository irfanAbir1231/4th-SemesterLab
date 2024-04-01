//irfan Hakim Bhuiyan
//SWE, Islamic University Of Technology
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000
#define   Irfan          ios::sync_with_stdio(false);cin.tie(0);
#define sqr(x) ((x) * (x))
#define test int t; cin >> t; while(t--)
typedef long long ll;
 
signed main()
{
    Irfan
    
    ll n;
    cin>>n;

    ll a[n];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }

    ll max_sum=a[0];
    ll sum=0;
    for(ll i=0;i<n;i++)
    {
        sum+=a[i];
        if(sum>max_sum)
        {
            max_sum=sum;
        }
        if(sum<0)
        {
            sum=0;
        }
    }

    cout<<max_sum<<endl;


 
return 0;
}