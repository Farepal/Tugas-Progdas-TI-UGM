#include <iostream>
#include <string>

using namespace std;

class dayType {
    public :
        string kindOfDay [7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        string day;
        int ind;

        dayType (string sans){
            day = sans;
            //ngatasin kalo angka depannya kaga kapital
            if (int(day[0]) < 65 or int(day[0]) > 91)
                day[0] = day[0] - 32;//char itu bisa berupa integer "googling ASCII"

            for (int i = 0; i < 7; i++){
                if (day == kindOfDay[i]){
                    ind = i;
                    break;
                }
            }
        }
        //return day (c)
        string Day (){
            return day;
        }
        //return next day (d)
        string nextDay (){
            return (ind == 6 ? kindOfDay[0] : kindOfDay[ind+1]);
        }
        //return previous day (e)
        string prevDay (){
            return (ind == 0 ? kindOfDay[6] : kindOfDay[ind-1]);
        }
        //f, hari apa setelah x hari setelah hari ini
        string addingDay (int x){
            return kindOfDay[(ind + x)%7];
        }
};

int main(){
    string inputan;
    cin >> inputan;
    //a, set the day
    dayType hari(inputan);
    //b, print the day
    cout << hari.day << endl;
    return 0;
}
