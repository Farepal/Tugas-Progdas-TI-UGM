#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
string memperbaruikata(string katalama)
{//yang diperbarui kalo misal ada huruf besar maka dikecilin, kalo ada kata selain huruf dan angka maka dihapus
    string katabaru = "";
    int sizekatalama = katalama.length(); //di string method length() dan size() itu sama
    for (int i = 0; i < sizekatalama; i++)
    {
        char masinghuruf = katalama[i];
        int decimalofmasinghuruf = int(masinghuruf);
        //suatu char bisa berupa integer, coba googling ascii
        //contoh char di bawah ini, suatu angka bisa berupa string juga, ingat string adalah arraynya char
        //0-9 (48-57) a-z(65-90) a-z(97-122) ascii char to decimal
        if (decimalofmasinghuruf >= 65 and decimalofmasinghuruf <= 90)
            katabaru += (char(decimalofmasinghuruf + 32));
        else if (decimalofmasinghuruf >= 97 and decimalofmasinghuruf <= 122 or decimalofmasinghuruf >= 48 and decimalofmasinghuruf <= 57)
            katabaru += masinghuruf;
    }
    return katabaru;
}

int main()
{
    vector <string> masingkata;
    //pembuatan object dengan class ifstream buat read file
    ifstream fileinput;
    fileinput.open("input.txt");

    //apakah ada file input.txt
    if (!fileinput.is_open())
    {
        cout << "tidak ada file input.txt atau salah nama atau input.txt tidak satu folder dengan file cpp ini" << endl;
        return 0;
    }

    while (!fileinput.eof())
    {
        string katadariinput;
        fileinput >> katadariinput;
        katadariinput = memperbaruikata(katadariinput);
        if (katadariinput.length() != 0)
            masingkata.push_back(katadariinput);
    }
    fileinput.close();//menutup file

    //pembuatan objek dengan class ofstream buat write file json
    string tojson = "";
    tojson += "{\n";
    cout << "kata\t\t\t" << "jumlah\t" << "histogram" << endl;
    for (auto i = masingkata.begin(); i != masingkata.end(); i++)
    {
        vector <string>::iterator it = find(masingkata.begin(), masingkata.end(), *i);//find itu function library algorith
        if (it-masingkata.begin() == i-masingkata.begin())
        {
            int jumlahberulang = count(masingkata.begin(), masingkata.end(), *i);
            cout << *i << ((*i).length() > 7 ? "\t\t":"\t\t\t") << jumlahberulang << "\t";
            for (int j = 0; j < jumlahberulang; j++)
                cout << "#";
            cout << endl;
            tojson += "\t\"";
            tojson += *i;
            tojson += "\": ";
            tojson += to_string(jumlahberulang);
            tojson += ",\n";
        }
    }
    tojson.erase(tojson.length()-2, 1);
    tojson += "}";
    ofstream filejson;
    filejson.open("output.json");
    filejson << tojson;
    filejson.close();

    return 0;
}
