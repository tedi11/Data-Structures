#include <iostream>
#include <algorithm>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;
ifstream f("testX.in");

long long n, v[100000005], ok = 1, val, k, i, j, d;

void printArray(long long v[], long long n)
{
    for (i=0; i<n; i++)
        cout << v[i] << " ";
    cout<<endl;
}

void QuickSort(long long st, long long dr)
{
    if(st < dr)
    {
        long long m = (st + dr)/2;
        swap(v[st],v[m]);
        i = st, j = dr, d = 0;
        while(i < j)
        {
            if(v[i] > v[j])
            {
                swap(v[i],v[j]);
                d = 1 - d;
            }
            i += d;
            j -= 1 - d;
        }
        QuickSort(st, i - 1);
        QuickSort(i + 1, dr);
    }
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

    QuickSort(0, n - 1);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    for(i = 0; i<n-1; ++i)
        if(v[i] > v[i+1])
            ok = 0;
    if(ok == 1)
        cout<<"TRUE"<<endl;
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
    cout<<"Acesta a fost algoritmul de Quicksort";
    return 0;
}
