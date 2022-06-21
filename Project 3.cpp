#include <iostream>

using namespace std;

int main() {
    int toothpicks = 23, human_pick, remaining, computer_pick;
    char retry;

    cout << "Let's Play a game of '23'! " << endl;
    cout << "Enter the number of sticks you wish to pick:" << endl;
    do {
        
        //Vaildate the user input for numbers
        while (!(cin >> human_pick)) {
            cout << "Please enter a vaild number" << endl;
            cin.clear();
            cin.ignore(100, '\n');
        }
        // Player has to draw under 4 tooth sticks
        while (human_pick >=4) {
            cout << "Wrong number of sticks, please pick 1, 2,or 3 sticks. Try again: ";
            cin >> human_pick;
        }

        remaining = toothpicks - human_pick;
        cout << "You picked:" << human_pick << " sticks. " << remaining << "left" << endl;
        // computer's turn
        if (remaining > 4)
            computer_pick = 4 - human_pick;
        if (remaining >= 2 && remaining <= 4)
            computer_pick = remaining - 1;
        if (remaining == 1) {
            cout << "Computer lose" << endl;
            break;
        }
        //player's turn
        remaining = remaining - computer_pick;
        cout << "Computer picked " << computer_pick << " sticks " << remaining << "left" << endl;

        if (remaining == 1) {
            cout << " 1 left and You lose" << endl;
            break;
        }
        cout << "Your turn. Enter the number of sticks you wish to pick: " << endl;
        toothpicks = remaining;

    } while (remaining > 0);

    cout << "Do you want to play again? Y/N" << endl;
    cin >> retry;
    if (retry == 'Y' || retry == 'y')
        main();

}
