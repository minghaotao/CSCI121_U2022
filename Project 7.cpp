//
// Created by Edward T on 8/27/21.
//
#include<iostream>

using namespace std;

void fill_array(int arr[], int size);

// pre-condition: The arr has actual size that is greater than or equal to size
// post-condition: arr[0], ..., arr[size-1] is filled from keyboard
void print_array(int arr[], int size);

// pre-condition: The arr has actual size that is greater than or equal to size
// post-condition: arr[0], ..., arr[size-1] is printed to screen with 5 elements per line
int linear_search(int arr[], int size, int key);

// pre-condition: arr has given size
// post-condition: The index of first occurrence of key in arr is returned. If the key cannot be found in arr, -1 is returned
void select_sort(int arr[], int size);

// pre-condition: arr has given size Of course, a menu function is needed. The main  function will look like following:
// post-condition: the elements in arr are rearranged from least to largest
void insert_sort(int arr[], int size);

// pre-condition: arr has given size
// post-condition: the elements in arr are rearranged from least to largest
void bubble_sort(int arr[], int size);

// pre-condition: arr has given size
// post-condition: the elements in arr are rearranged from least to largest
void menu();

int main() {
    int choice;
    int a[9];
    do {
        menu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                fill_array(a, 9);
                cout << "Enter the key you want to search: ";
                int key;
                cin >> key;
                int index = linear_search(a, 9, key);
                if (index == -1)
                    cout << "The key " << key << " is not in array\n";
                else
                    cout << "The key " << key << " is # " << (index + 1) << "element in array\n";
                break;
            }
            case 2: {
                fill_array(a, 9);
                select_sort(a, 9);
                cout << "After sort, the array is:\n";
                print_array(a, 9);
                break;
            }
            case 3:
//                This is a good example to show how to write the test program to test functions.
            {
                fill_array(a, 9);
                insert_sort(a, 9);
                cout << "After sort, the array is:\n";
                print_array(a, 9);
                break;
            }
            case 4: {
                fill_array(a, 9);
                bubble_sort(a, 9);
                cout << "After sort, the array is:\n";
                print_array(a, 9);
                break;
            }
            case 5: {
                cout << "Thank you for using the array functions\n";
                break;
            }
            default: {
                cout << "Wrong choice. Please choose from menu: ";
                break;
            }
        }
    } while (choice != 5);
    return 0;
}

void menu() {
    cout << "|**                Menu            **|" << endl;
    cout << "|** 1. Search the key in the array **|" << endl;
    cout << "|** 2. Select array                **|" << endl;
    cout << "|** 3. Insert search array         **|" << endl;
    cout << "|** 4. Bubble search array         **|" << endl;
    cout << "|** 5. Quit                        **|" << endl;
}

void fill_array(int arr[], int size) {

    cout << "Please enter " << size << " number from keyboard" << endl;

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
};

int linear_search(int arr[], int size, int key) {

    for (int i = 0; i < size; i++) {
        if (key == arr[i])
            return i;
    }
    return -1;

}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << endl;
    }
};

void swapValues(int &x, int &y) {
    int tem = x;
    x = y;
    y = tem;
};

void select_sort(int arr[], int size) {
   int i, j, min_index;
   for (i=0;i < size -1;i++){
       min_index = i;
       for (j = i+1;j <size; j++){
           if (arr[j] < arr[min_index])
               min_index = j;
       }
       swapValues(arr[min_index],arr[i]);

   }
};

void insert_sort(int arr[], int size) {

    for (int i = 1;i<size;i++){
        int j = i;

        while (j >0 && arr[j] < arr[j-1]){
            swapValues(arr[j],arr[j-1]);
            j--;
        }


    }
};

void bubble_sort(int arr[], int size) {
    int i, j, index;
    for ( i = 0; i < size - 1; i++) {
         index = i;
        for ( j = index + 1; j < size; j++) {
            if (arr[index] > arr[j]) {
                swapValues(arr[index], arr[j]);
            }
        }
    }
};
