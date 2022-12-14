#include <iostream>
using namespace std;
int n;

void iter ()
{
    for (int i = 2; i <= 5*n-3; i += 5)
        cout << i << ((i == 5*n-3) ? "\n": ", ");
}

void rek (int i)
{
    if (i == 1)
    {
        cout << 2 << ", ";
    }
    else 
    {
        rek (i-1);
        cout << 5*i-3 << ((i==n) ? "\n": ", ");
    }
}

int main(){
    cout << "Masukkan berapa banyak deret : ";
    cin >> n;
    cout << "Dengan Iterasi" << endl;
    iter ();
    cout << "Dengan Rekursi" << endl;
    rek (n);
    return 0;
}
