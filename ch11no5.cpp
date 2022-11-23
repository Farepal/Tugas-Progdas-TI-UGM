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
        int getMonth();
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
        string getPhoneNumber();
        string getClasify();
        void printAllInformation();
};

class addressBookType 
{
    public:
        vector <extPersonType> person;
        int index;
        addressBookType (int ind);
        void sortTheBook();//5eii
        void findLastNameInBook(string belakan);//5ciii dan 5civ
        void findNameInGivenMonth(int bulan);//5cv
        void printTheNameBetweenTwoLastNames(string lastAwal, string lastAkhir);//5cvi
        void yourRequest (string req);//5cvii
        void printTheBook();
};

int main()
{
    addressBookType BukuFarrel(0);
    BukuFarrel.sortTheBook();
    BukuFarrel.printTheBook();
    string namaBelakang;
    cout << "ingin mencari info orang sesuai nama Belakangnya ? " << endl;
    cin >> namaBelakang;
    BukuFarrel.findLastNameInBook(namaBelakang);
    cout << "Berikan Bulan : " << endl;
    int bul;
    cin >> bul;
    BukuFarrel.findNameInGivenMonth(bul);
    string last1, last2;
    cin >> last1 >> last2;
    BukuFarrel.printTheNameBetweenTwoLastNames(last1, last2);
    int ax;
    cout << "1.Family Member, 2. Friends, 3. Business" << endl;
    cin >> ax;
    string req;
    if (ax == 1) req = "FamilyMember";
    else if (ax == 2) req = "Friends";
    else if (ax == 3) req = "Business";
    BukuFarrel.yourRequest(req);

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

int dateType::getMonth()
{
    return dateType::month;
}

///extPersonType//////
void extPersonType::printAllInformation()
{
    personType::print();
    addressType::print();
    cout << "Date of Birth \t: "; dateType::print();
    cout << "Phone Number \t: " << phoneNumber << endl;
    cout << "Classify \t: " << classify << endl;
}

string extPersonType::getPhoneNumber()
{
    return extPersonType::phoneNumber;
}

string extPersonType::getClasify()
{
    return extPersonType::classify;
}

//////addressBookType/////////////////
addressBookType::addressBookType(int ind)
{
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
    addressBookType::index = sz-1;
}

void addressBookType::sortTheBook()
{
    for (int i = 0; i < index; i++)
    {
        for (int j = i+1; j <= index; j++)
        {
            if (addressBookType::person[j].getLastName() < addressBookType::person[i].getLastName())
            {
                extPersonType temp = addressBookType::person[i];
                addressBookType::person[i] = addressBookType::person[j];
                addressBookType::person[j] = temp;
            }
        }
    }
}

void addressBookType::printTheBook()
{
    for (int i = 0; i < addressBookType::person.size(); i++)
    {
        cout << i+1 << endl;
        addressBookType::person[i].printAllInformation();
    }
}

void addressBookType::findLastNameInBook(string belakan)
{
    vector <int> hasilIndex;
    for (int i = 0; i <= addressBookType::index; i++)
        if (belakan == addressBookType::person[i].getLastName())
            hasilIndex.push_back(i);
    for (int i = 0; i < hasilIndex.size(); i++)
    {
        //print  the address, phonenumber, date of birth
        person[hasilIndex[i]].personType::print();
        cout << "Street \t\t: " << person[hasilIndex[i]].getStreetAddress() << endl;
        cout << "Phone Number \t: " << person[hasilIndex[i]].getPhoneNumber() << endl;
        cout << "Date of Birth \t: "; person[hasilIndex[i]].dateType::print();
    }
}

void addressBookType::findNameInGivenMonth(int bulan)
{
    vector <int> hasilIndex;
    for (int i = 0; i <= addressBookType::index; i++)
        if (bulan == addressBookType::person[i].dateType::getMonth())
            hasilIndex.push_back(i);
    for (int i = 0; i < hasilIndex.size(); i++)
        person[hasilIndex[i]].personType::print();
}

void addressBookType::printTheNameBetweenTwoLastNames(string lastAwal, string lastAkhir)
{
    for (int i = 0; i <= addressBookType::index; i++)
    {
        if (person[i].getLastName() > lastAwal and person[i].getLastName() < lastAkhir)
            person[i].personType::print();
    }
}

void addressBookType::yourRequest(string req)
{
    for (int i = 0; i <= addressBookType::index; i++)
    {
        if (person[i].getClasify() == req)
            person[i].personType::print();
    }
}