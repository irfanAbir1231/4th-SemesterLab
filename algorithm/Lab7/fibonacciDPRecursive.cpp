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

struct fibonacciDPRecursive
{
    int fib(int n)
    {
        int f[n+2];
        f[0] = 0;
        f[1] = 1;
        int i;
        // if(n<=1)
        // {
        //     return n;
        // }
        for(i=2;i<=n;i++)
        {
            f[i]=f[i-1]+f[i-2];
        }
        return f[n];
    }
};

 
signed main()
{
    Irfan

    fibonacciDPRecursive obj;
    int n;
    cin>>n;
    cout<<obj.fib(n)<<endl;
    
    
 
return 0;
}