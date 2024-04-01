#include<bits/stdc++.h>
using namespace std;

int cutRod(vector<int> &price, int n)
{
    if(n <= 0)
        return 0;
    int max_val = INT_MIN;
    for(int i=0; i<n; i++)
        max_val = max(max_val, price[i] + cutRod(price, n-i-1));
    return max_val;
}

int main()
{
    int n;
    cin >> n;

    vector<int> price(n);
    for(int i=0; i<n; i++){
        cin >> price[i];
        if(price[i]==-1) break;
    }

    cout << "Maximum profit is " << cutRod(price, n) << endl;
    return 0;
}