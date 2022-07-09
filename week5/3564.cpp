/*
* @Author: Spare Lin
* @Project: AcWing2022
* @Date: 2022/7/5 9:29
* @Description: 3564. 日期类 来源：北京理工大学考研机试题
*/

#include <iostream>
#include <iomanip>

using namespace std;

int months[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,};

class Date {
private:
    int year, month, day;
public:
    Date(int year_, int month_, int day_) : year(year_), month(month_), day(day_) {}

    int getYear() const {
        return year;
    }

    int getMonth() const {
        return month;
    }

    int getDay() const {
        return day;
    }

    void updateNextDay() {
        if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0) {
            months[2] = 29;
        }
        if (day < months[month])
            day++;
        else if (day >= months[month]) {
            day = 1;
            if (month < 12) month++;
            else {
                month = 1;
                year++;
            }
        }
    }

};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int y, m, d;
        cin >> y >> m >> d;
        Date date(y, m, d);
        date.updateNextDay();
        cout << date.getYear() << '-';
        cout << setfill('0') << setw(2) << date.getMonth() << '-';
        cout << setfill('0') << setw(2) << date.getDay() << '\n';
    }
    return 0;
}
