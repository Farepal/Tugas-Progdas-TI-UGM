#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
using namespace std;
using namespace std::chrono;

vector<int> values(100000);

void algo1(int n)
{
    cout << "INPUT : " << n << endl;
    auto start = high_resolution_clock::now();
    n--;
    int x = values[n] + values[100000-n-1];
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Waktu yang digunakan algoritma: " << duration.count() << " microseconds" << endl;
}

void algon(int n)
{
    cout << "INPUT : " << n << endl;
    auto start = high_resolution_clock::now();
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum = sum + values[i];
    int rate = sum / n;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Waktu yang digunakan algoritma: " << duration.count() << " microseconds" << endl;
}

void algonn(int n)
{
    cout << "INPUT : " << n << endl;
    auto start = high_resolution_clock::now();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (values[j] > values[j + 1])
            {
                int temp = values[j];
                values[j] = values[j+1];
                values[j+1] = temp;
            }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Waktu yang digunakan algoritma: " << duration.count() << " microseconds" << endl;
}


int main()
{
    auto f = []() -> int{ return rand() % 10000; };
    generate(values.begin(), values.end(), f);
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    for (int n = 10; n <= 100000; n*=10)
    {
        auto f = []() -> int{ return rand() % 10000; };
        generate(values.begin(), values.end(), f);
        algonn(n);
    }

    return 0;
}