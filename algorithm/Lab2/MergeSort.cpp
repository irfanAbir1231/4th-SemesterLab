#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void merge(int arr[], int l, int m, int r)
{
    int n1 = m-l+1;
    int n2 = r-m;
    int L[n1], R[n2];
    for(int i=0;i<n1;i++)
        L[i] = arr[l+i];
    for(int i=0;i<n2;i++)
        R[i] = arr[m+1+i];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while(i<n1)
        arr[k++] = L[i++];
    while(j<n2)
        arr[k++] = R[j++];
}
 
signed main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    // Merge Sort
    int l=0, r=n-1;
    while(l<r)
    {
        int m = l+(r-l)/2;
        merge(arr,l,m,r);
        l = m+1;
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    
    
 
return 0;
}