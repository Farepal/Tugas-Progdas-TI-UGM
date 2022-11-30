#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
//0-9 (48-57) A-Z(65-90) a-z(97-122) ASCII char to decimal
string memperbaruiKata(string kataLama)
{
    string kataBaru = "";
    int sizeKataLama = kataLama.length(); //di string method length() dan size() itu sama
    for (int i = 0; i < sizeKataLama; i++)
    {
        char masingHuruf = kataLama[i];
        if (int(masingHuruf) >= 65 and int(masingHuruf) <=90)
            kataBaru += (char(int(masingHuruf) + 32));
        else if (int(masingHuruf) >= 97 and int(masingHuruf) <= 122)
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
        cout << "Tidak ada File input.txt atau mungkin salah nama" << endl;
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
    ofstream FileJson;
    FileJson.open("output.json");
    FileJson << "{\n";

    for (int i = 0; i < masingKata.size(); i++)
    {
        vector <string>::iterator it = find(masingKata.begin(), masingKata.end(), masingKata[i]);
        if (it - masingKata.begin() == i)
            FileJson << "\t\"" << masingKata[i] << "\" : " << to_string(count
            (masingKata.begin(), masingKata.end(), masingKata[i])) << (i == masingKata.size() - 1 ? "\n" : ",\n");
    }

    FileJson << "}";
    FileJson.close();
    return 0;
}
