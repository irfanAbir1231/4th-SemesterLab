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
    
    int n, k;
    cin >> n >> k;

    vector<int> h(n);

    for(int i=0; i<n; i++)
        cin >> h[i];

    vector<int> dp(n, INT_MAX);

    dp[0] = 0;

    for(int i=1; i<n; i++)
    {
        for(int j=1; j<=k; j++)
        {
            if(i-j >= 0)
                dp[i] = min(dp[i], dp[i-j] + abs(h[i] - h[i-j]));
        }
    }

    cout << dp[n-1] << endl;
 
return 0;
}