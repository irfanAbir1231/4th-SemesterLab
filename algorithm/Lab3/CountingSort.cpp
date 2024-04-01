#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
signed main()
{
    
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    ll max1=INT_MIN;
    for(ll i=0;i<n;i++)
    {
        max1=max(max1,a[i]);
    }
    ll b[max1+1];
    for(ll i=0;i<=max1;i++)
    {
        b[i]=0;
    }
    for(ll i=0;i<n;i++)
    {
        b[a[i]]++;
    }
    for(ll i=1;i<=max1;i++)
    {
        b[i]=b[i]+b[i-1];
    }
    ll c[n];
    for(ll i=n-1;i>=0;i--)
    {
        c[b[a[i]]-1]=a[i];
        b[a[i]]--;
    }
    for(ll i=0;i<n;i++)
    {
        cout<<c[i]<<" ";
    }
    cout<<endl;
 
return 0;
}