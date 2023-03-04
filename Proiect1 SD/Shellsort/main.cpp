#include <iostream>
#include <algorithm>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;
ifstream f("testX.in");

long long v[100000005],val, a, j, i, n, aux, ok=1;

int shellSort(long long v[], long long n)
{
    for (long long p = n/2; p > 0; p /= 2)
    {
        for (i = p; i < n; i += 1)
        {
            long long aux = v[i];
            long long j;
            for (j = i; j >= p && v[j - p] > aux; j -= p)
                v[j] = v[j - p];
            v[j] = aux;
        }
    }
    return 0;
}

void printArray(long long v[], long long n)
{
    for (i=0; i<n; i++)
        cout << v[i] << " ";
}

int main()
{

    while(f>>val)
    {
        v[i] = val;
        n++;
        i++;
    }
    auto start = high_resolution_clock::now();
    shellSort(v, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    //printArray(v, n);
    for(i = 0; i<n-1; ++i)
        if(v[i] > v[i+1])
            ok = 0;

    if(ok == 1)
        cout<<"TRUE"<<endl;
    cout<<endl;
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
    cout<<"Acesta a fost algoritmul de Shellsort";
    return 0;
}
