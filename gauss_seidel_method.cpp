// Author: Nirupam Pal
// Date: 09/08/2023
// Description: This program solves linear equations using gauss-seidel method

#include <iostream>
using namespace std;
#define ITER_NO 100

// Creating the necessary variables

int main() {

    cout << "*-----------------------------------------*-----------------------------------------*" << endl;
    cout << "|                                 Author: Nirupam Pal                               |" << endl;
    cout << "|                                   Date: 09/08/2023                                |" << endl;
    cout << "|    Description: This program solves linear equations using gauss-seidel method    |" << endl;
    cout << "*-----------------------------------------*---------------------------------------- *" << endl;

    int n, choice;

    cout << "Enter the number of variables to be solved : ";
    cin >> n;
    cout << "Enter the equations in the diagonal dominance form." << endl;
    float a[n][n], b[n], x[n], z = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "A[" << i+1 << "][" << j+1 << "] : ";
            cin >> a[i][j];
        }
        cout << "b[" << i+1 << "] : ";
        cin >> b[i];
    }
    cout << "Enter the initial guesses for the variables." << endl;
    cout << "Select '1' to enter the guesses manually or '0' to enter it automatically : "; 
    cin >> choice;
    if (choice == 1) {
        for (int i = 0; i < n; i++) {
            cout << "X[" << i+1 << "] : ";
            cin >> x[i];
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            x[i] = 0;
        }
    }
    int iteration = 0; 
    while (iteration < ITER_NO) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }
                else {
                    z += a[i][j] * x[j];
                }
            }
            x[i] = (b[i] - z) / a[i][i];
            z = 0;
        }
        iteration++;
        cout << "Iteration no. : " << iteration << endl;
        for (int i = 0; i < n; i++) {
            cout << "X[" << i+1 << "] = " << x[i] << endl;
    }
    }
    cout << "\nFinal solution : " << endl;
    for (int i = 0; i < n; i++) {
        cout << "X[" << i+1 << "] = " << x[i] << endl;
    }
    return 0;
}