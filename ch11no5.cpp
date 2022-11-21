//Jangan cuma dicopas tetapi dipahami logika pemrograman kalo binggung chat aja 088977772814
//kodenya buat sendiri, kode ini buat bahan referensi aja
#include <iostream>
#include <string>
#include <vector>

using namespace std;
//class persontType diambil dari example 10-10 di buku
class personType
{
    public:
        void print() const;
        void setName(string first, string last);
        string getFirstName() const;
        string getLastName() const;
        personType(string first, string last);
    private:
        string firstName; //variable to store the first name
        string lastName; //variable to store the last name
};

class dateType
{
    public:
        dateType(int bulan, int hari, int tahun);
        bool isLeapYear();
        void print() const;
    private:
        int month;
        int day;
        int year;
};
//soal 5a
class addressType 
{
    public :
        //Constructor
        addressType(string streetAddress, string city, string state, string ZIPcode);
        //funtion to get
        string getStreetAddress();
        string getCity();
        string getState();
        string getZIPcode();
        void print() const;//print semua member
    private :
        string streetAddress;
        string city;
        string state;
        string ZIPcode;
};
//soal 5b
class extPersonType: public addressType, public personType, public dateType
{
    private:
        string phoneNumber;
        string classify;
    public:
        extPersonType(string phoneNumber, string classify,
        string streetAddress, string city, string state, string ZIPcode, string first, string last, int bulan, int hari, int tahun) :
            addressType(streetAddress, city, state, ZIPcode),
            personType(first, last),
            dateType(bulan, hari, tahun)
        {
            extPersonType::phoneNumber = phoneNumber;
            extPersonType::classify = classify;
        }

        void printAllInformation()
        {
            personType::print();
            addressType::print();
            dateType::print();
            cout << phoneNumber << endl;
            cout << classify << endl;
        }
};

class addressBookType {
    public:
        vector <extPersonType> person;
        int index;
        
        addressBookType (int index)
        {
            addressBookType::index = index;
            int sz;
            //cout << "Jumlah keluarga" << endl;
            cin >> sz;
            for (int i = 0; i < sz; i++)
            {
                string First, Last, streetAddress, city, state, ZIPcode, phoneNumber, classify;
                int bulan, hari, tahun;
                //cout << "Input first name : ";
                cin >> First;
                //cout << "Input last name : ";
                cin >> Last;
                //cout << "Input street address : ";
                cin >> streetAddress;
                //cout << "Input city : ";
                cin >> city;
                //cout << "Input state : ";
                cin >> state;
                //cout << "Input ZIP Code : ";
                cin >> ZIPcode;
                //cout << "Input Phone Number : ";
                cin >> phoneNumber;
                //cout << "Input Classify : ";
                cin >> classify;
                //cout << "Input date of birth (mm/dd/yyyy) : ";
                cin >> bulan >> hari >> tahun;
                person.push_back(extPersonType(phoneNumber,classify,
                streetAddress, city, state, ZIPcode, First, 
                Last, bulan, hari, tahun)); 
            }
        }

        void sortTheBook()
        {
            for (int i = 0; i < index; i++)
            {
                for (int j = i+1; j <= index; j++)
                {
                    if (person[j].getLastName() < person[i].getLastName())
                    {
                        extPersonType temp = person[i];
                        person[i] = person[j];
                        person[j] = temp;
                    }
                }
            }
        }

        void printTheBook()
        {
            for (int i = 0; i < person.size(); i++)
            {
                cout << i << endl;
                person[i].printAllInformation();
            }
        }
};

int main()
{
    addressBookType BukuFarrel(0);
    BukuFarrel.sortTheBook();
    BukuFarrel.printTheBook();
    return 0;
}

////////addressType///////////////////
addressType::addressType(string streetAddress, string city, string state, string ZIPcode)
{
    this->streetAddress = streetAddress;
    this->city = city;
    this->state = state;
    this->ZIPcode = ZIPcode;
}

string addressType::getStreetAddress()
{
    return streetAddress;
}

string addressType::getCity()
{
    return city;
}

string addressType::getState()
{
    return state;
}

string addressType::getZIPcode()
{
    return ZIPcode;
}

void addressType::print() const
{
    cout << "street address \t: " << streetAddress << endl;
    cout << "city \t\t: " << city << endl;
    cout << "state \t\t: " << state << endl;
    cout << "ZIP code \t: " << ZIPcode << endl;
}

//////////personType////////////////////
void personType::print() const
{
    cout << firstName << " " << lastName << endl;
}

void personType::setName(string first, string last)
{
    firstName = first;
    lastName = last;
}

string personType::getFirstName() const
{
    return firstName;
}

string personType::getLastName() const
{
    return lastName;
}

personType::personType(string first, string last)//constructor
{
    firstName = first;
    lastName = last;
}

////////////////dateType///////////////////////////
bool dateType::isLeapYear()
{
    if (year % 400 == 0)
        return true;
    else if (year % 100 == 0)
        return false;
    else if (year % 4 == 0)
        return true;
    return false;
}

dateType::dateType (int bulan, int hari, int tahun)
{
    bool flagBulan = true;
    bool flagHari = true;
    bool flagTahun = true;

    if (bulan < 1 or bulan > 12)
    {
        cout << "There is no such month number" << endl;
        flagBulan = false;
    }

    if (flagBulan)
        this->month = bulan;

    if (tahun < 1)
    {
        cout << "There is no such year number" << endl;
        flagTahun = false;
    }

    if (flagTahun)
        this->year = tahun;

    if (hari < 1)
    {
        cout << "There is no such day number" << endl;
        flagHari = false;
    }

    if (bulan == 2)
    {
        if (isLeapYear())
        {
            if (hari < 1 or hari > 29)
            {
                cout << "There is no such day number" << endl;
                flagHari = false;
            }
        }
        else if (hari < 1 or hari > 28)
        {
            cout << "There is no such day number" << endl;
            flagHari = false;
        }
    }
    else if (bulan >= 1 and bulan <= 7)
    {
        if (bulan % 2 == 0)
        {
            if (hari < 1 or hari > 30)
            {
                cout << "There is no such day number" << endl;
                flagHari = false;
            }
        }
        else if (hari < 1 or hari > 31)
        {
            cout << "There is no such day number" << endl;
            flagHari = false;
        }
    }
    else if (bulan >= 8 and bulan <= 12){
        if (bulan % 2 == 1)
        {
            if (hari < 1 or hari > 30)
            {
                cout << "There is no such day number" << endl;
                flagHari = false;
            }
        }
        else if (hari < 1 or hari > 31)
        {
            cout << "There is no such day number" << endl;
            flagHari = false;
        }
    }

    if (flagHari)
        this->day = hari;
}

void dateType::print() const
{
    if (dateType::month == 1)
        cout << "January ";
    else if (dateType::month == 2)
        cout << "February ";
    else if (dateType::month == 3)
        cout << "March ";
    else if (dateType::month == 4)
        cout << "April ";
    else if (dateType::month == 5)
        cout << "May ";
    else if (dateType::month == 6)
        cout << "June ";
    else if (dateType::month == 7)
        cout << "July ";
    else if (dateType::month == 8)
        cout << "August ";
    else if (dateType::month == 9)
        cout << "September ";
    else if (dateType::month == 10)
        cout << "October ";
    else if (dateType::month == 11)
        cout << "November ";
    else if (dateType::month == 12)
        cout << "December ";

    cout << day << ", " << year << endl;
}
