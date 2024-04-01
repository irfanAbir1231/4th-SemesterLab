#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }

    auto start = std::chrono::high_resolution_clock::now();

    for(int i=1;i<n;i++)
    {
        int current = v[i];
        int j=i-1;
        while(v[j]>current && j>=0)
        {
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=current;
    }
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;

    for(auto u : v)
    {
        cout<<u<<" ";
    }
    cout<<endl;

    std::cout << "Execution time: " << duration.count() << " seconds." << std::endl;
}