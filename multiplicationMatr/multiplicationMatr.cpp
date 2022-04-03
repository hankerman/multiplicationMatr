#include <iostream>
using namespace std;

void createMatr(int**& arr, int row, int cols) {

    arr = new int* [row];

    for (int i = 0; i < row; i++) {
        arr[i] = new int[cols];
    }

}

void fill(int**& arr, int row, int cols) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 100;
        }
    }
}

void print(int**& arr, int row, int cols) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void delMatr(int**& arr, int row) {
    for (int i = 0; i < row; i++) {
        delete[]arr[i];
    }
    delete[]arr;
}

int** multy(int** arr, int** arr2, int row, int row2, int cols, int cols2) {
    int** temp = nullptr;
    createMatr(temp, row, cols2);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < cols2; j++) {
            temp[i][j] = 0;
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < cols2; j++) {
            for (int t = 0; t < cols; t++) {
                temp[i][j] += arr[i][t] * arr2[t][j];
            }
        }
    }

    
    return temp;
}

int main()
{
    
    /*Напишите функцию умножения матриц.*/

    int row, cols, row2, cols2, row3, cols3;

    int** matr = nullptr;
    int** matr2 = nullptr;
    int** multiMatr = nullptr;

    cout << "Enter row: ";
    cin >> row;
    cout << "Enter cols: ";
    cin >> cols;
    cout << "Enter row2: ";
    cin >> row2;
    cout << "Enter cols2: ";
    cin >> cols2;
    row3 = row;
    cols3 = cols2;
    
    createMatr(matr, row, cols);
    createMatr(matr2, row2, cols2);
    
    fill(matr, row, cols);
    fill(matr2, row2, cols2);
        
    print(matr, row, cols);
    print(matr2, row2, cols2);

    if (cols == row2) {
        multiMatr = multy(matr, matr2, row, row2, cols, cols2);
        print(multiMatr, row3, cols3);
        delMatr(multiMatr, row3);
    }
    else {
        cout << "Errors" << endl;
    }
       

    delMatr(matr, row);
    delMatr(matr2, row2);
    
}