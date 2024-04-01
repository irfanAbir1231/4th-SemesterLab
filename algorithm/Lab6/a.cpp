//irfan Hakim Bhuiyan
//SWE, Islamic University Of Technology
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000
#define   Irfan          ios::sync_with_stdio(false);cin.tie(0);
#define sqr(x) ((x) * (x))
#define test int t; cin >> t; cin.ignore();  while(t--)
typedef long long ll;

const int N = 1e3+10;

int a[N][N];

void func(){
    a[0][0]=5;
}
 
signed main()
{
    a[0][0] = 7;

    cout<<a[0][0]<<endl;

    func();
    cout<<a[0][0]<<endl;

    
 
return 0;
}