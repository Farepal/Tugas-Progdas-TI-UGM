#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
string memperbaruiKata(string kataLama)
{//yang diperbarui kalo misal ada huruf besar maka dikecilin, kalo ada kata selain huruf dan angka maka dihapus
    string kataBaru = "";
    int sizeKataLama = kataLama.length(); //di string method length() dan size() itu sama
    for (int i = 0; i < sizeKataLama; i++)
    {
        char masingHuruf = kataLama[i];
        int DecimalOfMasingHuruf = int(masingHuruf);
        //suatu char bisa berupa integer, coba googling ASCII
        //contoh char di bawah ini, suatu angka bisa berupa string juga, ingat string adalah arraynya char
        //0-9 (48-57) A-Z(65-90) a-z(97-122) ASCII char to decimal
        if (DecimalOfMasingHuruf >= 65 and DecimalOfMasingHuruf <= 90)
            kataBaru += (char(DecimalOfMasingHuruf + 32));
        else if (DecimalOfMasingHuruf >= 97 and DecimalOfMasingHuruf <= 122 or DecimalOfMasingHuruf >= 48 and DecimalOfMasingHuruf <= 57)
            kataBaru += masingHuruf;
    }
    return kataBaru;
}

int main()
{
    vector <string> masingKata;
    //pembuatan object dengan class ifstream buat read file
    ifstream FileInput;
    FileInput.open("input.txt");

    //apakah ada file input.txt
    if (!FileInput.is_open())
    {
        cout << "Tidak ada File input.txt atau salah nama atau input.txt tidak satu folder dengan file cpp ini" << endl;
        return 0;
    }

    while (!FileInput.eof())
    {
        string kataDariInput;
        FileInput >> kataDariInput;
        kataDariInput = memperbaruiKata(kataDariInput);
        if (kataDariInput.length() != 0)
            masingKata.push_back(kataDariInput);
    }

    FileInput.close();//menutup file

    //pembuatan objek dengan class ofstream buat write file json
    string toJson = "";
    toJson += "{\n";

    for (auto i = masingKata.begin(); i != masingKata.end(); i++)
    {
        vector <string>::iterator it = find(masingKata.begin(), masingKata.end(), *i);//find itu function library algorith
        if (it-masingKata.begin() == i-masingKata.begin())
        {
            toJson += "\t\"";
            toJson += *i;
            toJson += "\": ";
            toJson += to_string(count(masingKata.begin(), masingKata.end(), *i));
            toJson += ",\n";
        }
    }
    toJson.erase(toJson.length()-2, 1);
    toJson += "}";
    ofstream FileJson;
    FileJson.open("output.json");
    FileJson << toJson;
    FileJson.close();
    return 0;
}
