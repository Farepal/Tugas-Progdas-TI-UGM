#include <iostream>

using namespace std;

void deklarasi(int n, int angka[])
{
    for (int i = 0; i < n; i++)
        cin >> angka[i];
}

void tampilkanGanjil(int n, int angka[])
{
    for (int i = 0; i < n; i++)
        if (angka[i] % 2 == 1)
            cout << angka[i] << " ";
}

int main()
{
    int angka[9999];
    int n;
    cout << "Masukkan jumlah angka : ";
    cin >> n;
    cout << "Masukkan deretnya dipisahkan dengan spoasi : ";
    deklarasi(n, angka);
    tampilkanGanjil(n, angka);
}
