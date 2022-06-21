//CSCI121_VA_F2021
//Project 2
// Created by Edward T on 8/27/21.
//Fort Hays State University

#include <iostream>

using namespace std;

int main() {
    char gender, choice;
    double weight, height, age;
    double bmr_f, bmr_m;
    double number_of_chocolate;

    do {
        cout << "Welcome to my BMR calcuator." << endl;
        cout << "Gender (M or F): ";
        cin >> gender;
        //gender input validation using while loop
        while (!(gender == 'm' || gender == 'M' || gender == 'f' || gender == 'F')) {
            cout << "Wrong gender input. Please enter again. Gender (M or F): ";
            cin >> gender;
        }
        cout << "Weight (in pounds): ";
        //cin >> weight;
        //optional-One example of validate the number input for weight, explanation - https://www.youtube.com/watch?v=YIX7UhIKEIk
        while (!(cin >> weight)) {
            cout << "Please enter a vaild number" << endl;
            cin.clear();
            cin.ignore(100, '\n');
        }
        cout << "Height (in inches): ";
        cin >> height;
        cout << "Age (in years): ";
        cin >> age;
        //You could just use if-else statment, I prefer using two if statement for code readability
        if (gender == 'F' || gender == 'f') {
            bmr_f = 655 + (4.3 * weight) + (4.7 * height) - (4.7 * age);
            number_of_chocolate = bmr_f / 240;
            cout << "She needs " << bmr_f << " calories to maintain her weight" << endl;
            cout << "That is about " << number_of_chocolate << "chocolate bar's calories. " << endl;
        }
        if (gender == 'm' || gender == 'M') {
            bmr_m = 66 + (4.3 * weight) + (12.9 * height) - (6.8 * age);
            number_of_chocolate = bmr_m / 240;
            cout << "He needs " << bmr_m << " calories to maintain his weight" << endl;
            cout << "That is about " << number_of_chocolate << " chocolate bar's calories. " << endl;
        }
        //Repeat the program using do-while loop
        cout << "Do you want to do another calucation? (Y/N) ";
        cin >> choice;
        // you can use the same gender while loop for choice validation
    } while (choice == 'Y' || choice == 'y');

    cout << "Thanks for using my BMR calculator. Good bye! ";

}
