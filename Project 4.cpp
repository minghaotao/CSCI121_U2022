//
// Created by Edward T on 8/10/21.
//
#include <iostream>

using namespace std;

void print_introduction();

double celsius_at_depth(double depth);

double celsius_to_fahrenheit(double celsius);

void print_conclusion(double depth);

int main() {
    double depth;
    char input;
    do {
        print_introduction();
        cin >> depth;
        print_conclusion(depth);
        cout << "Would you like to do it again? (Y/N):" << endl;
        cin >> input;
    } while (input == 'Y' || input == 'y');

}

void print_introduction() {

    cout << "Hello! The Program will tell you the temperature of the earth at any depth." << endl;
    cout << "Enter a depth in KM: " << endl;

}

double celsius_at_depth(double depth) {
    double celsius = 10 * depth + 20;
    return celsius;
}

double celsius_to_fahrenheit(double celsius) {
    return 1.8 * celsius + 32;
}

void print_conclusion(double depth) {
    double celsius = celsius_at_depth(depth);
    double fahrenheit = celsius_to_fahrenheit(celsius);
    cout << "The temperature of the earth at a depth of 10 KM is " << celsius << "Celsius, and "
    << fahrenheit << "in Fahrenheit." << endl;

}
