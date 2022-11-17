#include <iostream>

using namespace std;

void modul1(int i, int batas){
    for (;i < batas; i++)
        cout << i*5+2 << " ";
}

void modul2(int i, int batas){
    if (i < batas){
        cout << i*5+2 << " ";
        modul2(i+1, batas);
    }
}

int main(){
    modul1(0,4);
    cout << endl;
    modul2(0,4);
    cout << endl;
    return 0;
}
