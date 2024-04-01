#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
signed main()
{
    int n;
    cin>>n;
    pair<int,int> arr[n];
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        arr[i] = {a,b};
    }
    sort(arr,arr+n);
    for(int i=0;i<n-1;i++)
    {
        if(arr[i].second>arr[i+1].second)
        {
            cout<<"Happy Alex"<<endl;
            return 0;
        }
    }
    cout<<"Poor Alex"<<endl;
    
 
return 0;
}