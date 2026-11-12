#include <iostream>
using namespace std;

int main() {
    int* arr = new int[5];  // allocates and default-initializes 5 ints

    // Optional: initialize values to see clearer output
    for (int i = 0; i < 5; i++) arr[i] = i * 10;

    // print the array
    for (int i = 0; i < 5; i++) cout << arr[i] << " ";

    delete[] arr;  // deallocates the array
    
    cout << endl;
    int (*arr2)[4] = new int[3][4];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++)
            arr2[i][j] = i + j;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++)
            cout << arr2[i][j] << " ";
        cout << endl;
    }

    delete[] arr2;
    return 0;
}
