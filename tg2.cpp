#include <iostream>

using namespace std;

void cekGanjil (int num[], int szAr)
{
    for (int i = 0; i < szAr; i++)
    {
        if (num[i] % 2 == 1)
            cout << num[i] << " ";
    }
    cout << endl;
}

int main()
{
    int angka[] = {1,2,3,4,5,6,7,8,9,10};
    cekGanjil(angka, sizeof angka / sizeof angka[0]);
    return 0;
}
