#include <iostream>
#include <algorithm>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;
ifstream f("testX.in");

long long v[100000005], intt[100000005], i = 0, n = 0, val, ok =1;

void mergeSort(int st, int dr)
{
    if(st < dr)
    {
        int m = (st + dr) / 2;
        mergeSort(st , m);
        mergeSort(m + 1 , dr);

        int i = st, j = m + 1, k = 0;
        while( i <= m && j <= dr )
            if( v[i] < v[j])
                intt[++k] = v[i++];
            else
                intt[++k] = v[j++];
        while(i <= m)
            intt[++k] = v[i++];
        while(j <= dr)
            intt[++k] = v[j++];
        for(i = st , j = 1 ; i <= dr ; i ++ , j ++)
            v[i] = intt[j];
    }
}

int main(){

    while(f>>val)
    {
        v[i] = val;
        i++;
        n++;
    }

    auto start = high_resolution_clock::now();

    mergeSort(0 , n - 1);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    for(i = 0; i<n-1; ++i)
        if(v[i] > v[i+1])
                ok = 0;
    if(ok == 1)
        cout<<"TRUE"<<endl;
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
    cout<<"Acesta a fost algoritmul de Mergesort";
    return 0;
}
