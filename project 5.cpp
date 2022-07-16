//
// Created by Edward T on 8/11/21.
//
#include <iostream>

using namespace std;

void testMenu();

// post-condition: the test menu is displayed for choose
bool isLeapYear(int year);

int getCenturyValue(int year);

int getYearValue(int year);

int getMonthValue(int month, int year);

int dayOfWeek(int month, int day, int year);

string dayOfWeek(int day);

int validation(int year);

int validation_month(int month);

int validation_day(int day);

int main() {
    int choice;
    int day, month, year;
    do {

        testMenu();
        cout << "Please choose from menu: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Please enter a year ";
                cin >> year;
                year = validation(year);
                if (isLeapYear(year))
                    cout << "Year " << year << " is a leap year" << endl;
                else cout << "Year " << year << " is NOT a leap year" << endl;
                break;
            case 2:
                cout << "Please enter a year";
                cin >> year;
                year = validation(year);
                cout << "The cetury value is: " << getCenturyValue(year) << endl;
                break;
            case 3:
                cout << "Please enter a year: ";
                cin >> year;
                year = validation(year);
                cout << "The century value is: " << getYearValue(year) << endl;
                break;
            case 4:
                cout << "Please enter a year and month:";
                cin >> year >> month;
                year = validation(year);
                month = validation_month(month);
                cout << "The month value is: " << getMonthValue(month, year) << endl;
                break;
            case 5:
                cout << "Please enter a year, a month, and a day ";
                cin >> year >> month >> day;
                year = validation(year);
                month = validation_month(month);
                day = validation_day(day);
                cout << "The day of the week is: " << dayOfWeek(month, day, year) << endl;
                break;
            case 6:
                cout << "Please enter a day of week(0 for Sunday, 1 for Monday,etc): ";
                cin >> day;
                cout << "The name of the day of the week is: " << dayOfWeek(day) << endl;
                break;
            case 7:
                cout << "Did you tested all functions yet ? If not, please return the prorgam\n";
                break;
            default:
                cout << "Wrong option, please choose from menu\n";
                while (!(cin >> choice)) {
                    cout << "Wrong option, please choose from menu\n";
                    cin.clear();
                    cin.ignore(100, '\n');
                }
                break;
        }
//        system("read -n 1 -s -p 'Press any key to continue...'");


    } while (choice != 7);

}

void testMenu() {
    cout << "************************************" << endl;
    cout << " * Test Menu *" << endl;
    cout << "* 1. is LeapYear *" << endl;
    cout << "* 2. getCenturyValue *" << endl;
    cout << "* 3. getYearValue *" << endl;
    cout << "* 4. getMonthValue * " << endl;
    cout << "* 5. dayOfWeek(month, day, year) * " << endl;
    cout << "* 6. dayOfWeek(day) * " << endl;
    cout << "* 7. Quite * " << endl;
    cout << "************************************" << endl;
}

bool isLeapYear(int year) {
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        return true;
    else
        return false;
}

int getCenturyValue(int year) {
    return (3 - (year / 100) % 4) * 2;
}

int getYearValue(int year) {
    return (year % 100) / 4 + 8;
}

int getMonthValue(int month, int year) {
    int result;
    switch (month) {
        case 1:
            if (isLeapYear(year))
                result = 6;
            else result = 0;
            break;
        case 2:
            if (isLeapYear(year))
                result = 2;
            else
                result = 3;
            break;
        case 3:
        case 11:
            result = 3;
            break;
        case 4:
        case 7:
            result = 6;
            break;
        case 5:
            result = 1;
            break;
        case 6:
            result = 4;
            break;
        case 8:
            result = 2;
            break;
        case 9:
        case 12:
            result = 5;
            break;
        default: // case 10
            result = 0;
            break;
    }
    return result;
}

int dayOfWeek(int month, int day, int year) {
    int sum = day + getMonthValue(month, year) + getYearValue(year) + getCenturyValue(year);
    return sum % 7;
}

string dayOfWeek(int day) {

    while (!(day >= 0 && day < 7)) {
        cout << "Your day input is not vaild, please try again\n";
        cin >> day;

    }
    switch (day) {
        case 0:
            return "Sunday";
        case 1:
            return "Monday";
        case 2:
            return "Tuesday";
        case 3:
            return "Wednesday";
        case 4:
            return "Thursday";
        case 5:
            return "Friday";
        case 6:
            return "Saturday";
        default:
            return "Wrong input";
    }
}

int validation(int year) {
    while (!(year > 1582)) {
        cout << "your Year is not vaild, please try again and make sure year is later than 1582\n";
        cin >> year;
    }
    return year;
}

int validation_month(int month) {
    while (!(month >= 1 && month <= 12)) {
        cout << "Your month is not vaild, please try again and it is between [1-12]\n";
        cin >> month;
    }
    return month;
}

int validation_day(int day) {
    while (!(day >= 1 && day <= 31)) {
        cout << "Your day input is not vaild, please try again\n";
        cin >> day;

    }
    return day;
}
