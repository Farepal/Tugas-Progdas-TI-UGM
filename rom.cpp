#include <iostream>
#include <string>

using namespace std;

class romanType {
    public:
       string Romawi;
       int desimal;
       bool error = 0;
       romanType (string x);
};

int main(){
    string input;
    cout << "Input bilangan Romawi : ";
    cin >> input;
    romanType repalRom(input);
    if (!repalRom.error){
        char s;
        cout << "Masukkan Romawi atau Desimal (R/D) : ";
        cin >> s;
        if (s != 'R' and s != 'D')
            cout << "Tolong Masukkan hanya R atau D";
        else if (s == 'R' or s == 'r')
            cout << "Bilangan Romawinya adalah " <<repalRom.Romawi << endl;
        else if (s == 'D' or s == 'd')
            cout << "Bilangan Desimal dari " << repalRom.Romawi << " adalah " << repalRom.desimal << endl;
    }
    return 0;
}

romanType::romanType(string x){
    int xSize = x.size();
    int arrNumber[xSize];
    for (int i = 0; i < xSize; i++){
        if (x[i] == 'I')
            arrNumber[i] = 1;
        else if (x[i] == 'V')
            arrNumber[i] = 5;
        else if (x[i] == 'X')
            arrNumber[i] = 10;
        else if (x[i] == 'L')
            arrNumber[i] = 50;
        else if (x[i] == 'C')
            arrNumber[i] = 100;
        else if (x[i] == 'D')
            arrNumber[i] = 500;
        else if (x[i] == 'M')
            arrNumber[i] = 1000;
        else {
            cout << "Bilangan Romawi Invalid" << endl;
            this -> error = 1;
            break;
        }
    }

    int sum = 0;
    for (int i = 0; i < xSize; i++){
        if (i < xSize - 2 && arrNumber[i] < arrNumber[i+1] && arrNumber[i+1] < arrNumber[i+2]){
            cout << "Bilangan Romawi Invalid";
            this -> error = 1;
            break;
        }
        else if (i < xSize - 3 and arrNumber[i] == arrNumber[i+1] and arrNumber[i+1] == arrNumber[i+2] and arrNumber[i+2] == arrNumber[i+3]){
            cout << "Bilangan Romawi Invalid" << endl;
            this -> error = 1;
            break;
        }
        else if (i < xSize - 1 && arrNumber[i] < arrNumber[i+1]){
            sum += (arrNumber[i+1] - arrNumber[i]);
            i++;
        }
        else
            sum += arrNumber[i];
    }
    this -> desimal = sum;
    this -> Romawi = x;
}
