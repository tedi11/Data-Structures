#include <iostream>
#include <algorithm>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;
ifstream f("testX.in");

long long n, i, v[100000020], maxi,w[100000020], j, val, ok = 1;

void printArray(long long v[], long long n)
{
    for (i=0; i<n; i++)
        cout << v[i] << " ";
    cout<<endl;
}

int main()
{
    while(f>>val)
    {
        v[i] = val;
        i++;
        if (val > maxi)
            maxi = val;
    }
    n = i;

    auto start = high_resolution_clock::now();

    for(i = 0; i < n; i++)
        w[v[i]]++;

    for(i = 1; i <= maxi; ++i)
        while(w[i] > 0)
        {
            v[j] = i;
            j++;
            w[i]-=1;
        }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    //printArray(v, n);
    for(i = 0; i<n-1; ++i)
        if(v[i] > v[i+1])
            ok = 0;

    if(ok == 1)
        cout<<"TRUE"<<endl;
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
    cout<<"Acesta a fost algoritmul de Countsort";
    return 0;
}
