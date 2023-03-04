#include <iostream>
#include <algorithm>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;
ifstream f("testX.in");

long long v[100000005], i, j, k, m, n, val;
bool sorted;

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
        n++;
    }
    m = n;

    auto start = high_resolution_clock::now();

    do{
        sorted = true;
        int k = m;
        for(i = 0; i < k - 1; ++i)
            if(v[i] > v[i+1])
            {
                swap(v[i],v[i+1]);
                sorted = false;
                m = i + 1;
            }
    }while(!sorted);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    for(i = 0; i<n-1; ++i)
        if(v[i] > v[i+1])
            ok = 0;

    if(ok == 1)
        cout<<"TRUE"<<endl;
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
    cout<<"Acesta a fost algoritmul de Bubblesort";
    return 0;
}
