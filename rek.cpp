#include <iostream>
using namespace std;

void rek (int i){
    if (i < 4){
        cout << i*5+2 << " ";
        rek (i + 1);
    }
}

int main(){
    rek (0);
    return 0;
}
