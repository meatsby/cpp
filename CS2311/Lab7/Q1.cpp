#include <iostream>

using namespace std;

int main() {
    int num[10] = {5, 10, 2, 5, 8, 8, 7, 9, 1, 5};

    // Print the contents of the array
    cout << "The contents of the array are: " << endl;
    for (int i = 0; i < 10; i++) {
        cout << num[i] << endl;
    }

    // Print a bar chart for the values in the array
    cout << endl << "The bar chart for the values in the array is: " << endl;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < num[i]; j++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
