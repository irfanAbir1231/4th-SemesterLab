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
 
signed main()
{
    Irfan
    
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    vector<int> dp(n+1, INT_MIN);
    dp[0] = 0;

    for(int i=1; i<=n; i++)
    {
        if(i-a >= 0)
            dp[i] = max(dp[i], dp[i-a] + 1);
        if(i-b >= 0)
            dp[i] = max(dp[i], dp[i-b] + 1);
        if(i-c >= 0)
            dp[i] = max(dp[i], dp[i-c] + 1);
    }

    cout << dp[n] << endl;



 
return 0;
}