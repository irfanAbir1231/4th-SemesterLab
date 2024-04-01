#include<bits/stdc++.h>
using namespace std;

#define Irfan ios::sync_with_stdio(false);cin.tie(0);

typedef long long ll;

int main()
{
    Irfan

    int t;
    cin >> t;

    while(t--){
    
        ll n;
        cin >> n;
        ll sum1 = 0;
        ll flg = 0;

        
        ll a[n];
        for(ll i = 0; i < n; i++)
        {
            cin >> a[i]; 
        }

        ll max_sum = a[0]; 
        ll sum = 0;
        ll start_index = 0, end_index = -1; 
        for(ll i = 0; i < n; i++)
        {
            if(sum + a[i] >= 0) {
                if(sum == 0) {
                    start_index = i; 
                }
                sum += a[i];
                end_index = i; 
                max_sum = max(max_sum, sum);
            } else {
                sum = 0; 
            }
        }
        
        for(ll i = start_index; i <= end_index; i++) {
            if(a[i] >= 0) {
                sum1 += a[i];
                flg = 1;
            }
        }
        
        if(flg == 0) {
            sum1 = *max_element(a + start_index, a + end_index + 1);
        }
        cout << max_sum << " " << sum1 << endl;

    }

    return 0;
}
