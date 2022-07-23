//
// Created by Edward T on 8/30/21.
//
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void get_scores(vector<int> &v);

// get integer scores from keyboard and store in v.
// we assume that the user will input scores in range
// of 0 to 100, inclusive. User enter a negative
// number to stop the input and end the function
void print_stats(vector<int> &v);

// print out the stats of data that are stored in v
// includes: max, min, total number of data,
// and the average
bool is_palindrome(string sentence);
// return true if the sentence is a palindrome;
// false otherwise

int main() {
    vector<int> v;
    string sentence;
    char choice;

    do {
        cout << "This is Problem 1 function for Vector" << endl;
        get_scores(v);
        cout << "This Vector has: " << endl;
        print_stats(v);
        cout << "Do you want try another set of scores again? Y/N " << endl;
        cin >> choice;
        cin.ignore();
    } while (choice == 'Y' || choice == 'y');
    do {
        cout << "\n";
        cout << "This is Problem 2 function for Palindorme" << endl;
        cout << "Please enter a sentence: " << endl;
        getline(cin, sentence);
        if (is_palindrome(sentence))
            cout << sentence << " This is the Palindrome" << endl;
        else
            cout << sentence << " This is NOT the Palindrome" << endl;

        cout << "Do you want try another sentence? Y/N " << endl;
        cin >> choice;
        cin.ignore();
    } while (choice == 'Y' || choice == 'y');

}


void get_scores(vector<int> &v) {
    cout << "Please enter the number (0-100) from the keyboard, and enter -1 to stop " << endl;
    int number;
    cin >> number;
    while (number > 0 && number < 100) {
        v.push_back(number);
        cin >> number;
    }
    if (number < 0) {
        return;
    }

}

void print_stats(vector<int> &v) {
    int max = v[0], min = v[0];
    double sum = 0, average;
//    for (int i : v) {
//        cout << i << endl;
//        sum += i;
//        if (max <= i) {
//            max = i;
//        }
//        if (min >= i) {
//            min = i;
//        }
//    }
    // use-base range
    for (unsigned int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
        sum += v[i];
        if (max <= v[i]) {
            max = v[i];
        }
        if (min >= v[i]) {
            min = v[i];
        }
    }
    average = sum / v.size();
    cout << "\n";
    cout << "The total number of data is " << v.size() << endl;
    cout << "The Sum is " << sum << endl;
    cout << "The Average is " << average << endl;
    cout << "The max value is " << max << endl;
    cout << "The min value is " << min << endl;


};

bool is_palindrome(string sentence) {
    string clean_sentence, reversed_sentence;

    for (int i = 0; i < sentence.length(); i++) {

        while (!isalpha(sentence[i])) {
            sentence.erase(i, 1);
            cout << "error" << endl;
        }
        if (!isalpha(sentence[sentence.length() - 1])) {
            sentence.pop_back();
        }
        // if the last chatper is not alpha, remove it from the string to prevent the infitnae loop

//        clean_sentence += sentence[i];
        sentence[i] = tolower(sentence[i]);
        clean_sentence.push_back(sentence[i]);

    }

    for (int i = clean_sentence.size() - 1; i >= 0; i--) {
        reversed_sentence.push_back(clean_sentence[i]);
    }

    if (clean_sentence == reversed_sentence) {
        return true;
    }
    return false;

};
