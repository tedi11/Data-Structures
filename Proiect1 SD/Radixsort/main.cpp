#include <iostream>
#include <algorithm>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;
ifstream f("testX.in");

long long val, n, nrcif, i, v[100000009], maxi,imp = 1, x[100000009], ok =1;
double total = 0;

int k = 65536;
//int k = 2048;
//int k = 32768;
//int k = 4096;
//int k = 8192;
//int k = 1024;
//int k = 10;
int main()
{
    while(f>>val)
    {
        v[i] = val;

        n++;
        if (val > maxi) maxi = val;
        i++;
    }

    auto start = high_resolution_clock::now();

    while(maxi != 0)
    {
        int  w[k] = {0};
        for(int i = 0; i < n; ++i)
            w[((v[i]) /imp) % k]++;

        for (i = 1; i < k; ++i)
            w[i] += w[i - 1];

        for (i = n - 1; i >= 0; --i)
        {
            x[w[((v[i])/imp) % k] - 1] = v[i];
            w[((v[i])/imp) % k]--;
        }

        for (i = 0; i < n; ++i)
            v[i] = x[i];
        imp*=k;
        maxi/=k;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    for(i = 0; i<n-1; ++i)
        if(v[i] > v[i+1])
            ok = 0;

    if(ok == 1)
        cout<<"TRUE"<<endl;
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
    cout<<"Acesta a fost algoritmul Radixsort pentru k="<<k;
    return 0;

}
