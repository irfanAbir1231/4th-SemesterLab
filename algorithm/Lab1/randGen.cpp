#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int v[n];
    int N = 1000;
    for(int i=0;i<n;i++)
    {
        int a = rand();
        v[i]=a;
    }

    auto start = std::chrono::high_resolution_clock::now();

    int counter=1;
    int temp=0;
    while(counter<n)
    {
        for(int i=0;i<n-counter;i++)
        {
            if(v[i]>v[i+1])
            {
                swap(v[i+1],v[i]);
            }
        }
        counter++;
    }

    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    auto end = std::chrono::high_resolution_clock::now();

    chrono::duration<double> duration = end - start;
  
    cout<<endl;
    cout << "Execution time: " << duration.count() << " seconds." << endl;
    return 0;
}