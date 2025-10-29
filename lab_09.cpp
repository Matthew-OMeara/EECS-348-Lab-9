#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

void printMatrix(std::vector<std::vector<int> >& matrix) {
    int N = matrix.size();
    int max_width = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int current_width = to_string(matrix[i][j]).length();
            if (current_width > max_width) {
                max_width = current_width;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << setw(max_width+2) << matrix[i][j];
        }
        cout << endl;
    }
}

bool loadMartices(string& filename, std::vector<std::vector<int> >& matrix1, std::vector<std::vector<int> >& matrix2) {
    std::ifstream inputFile(filename);

    int N;
    inputFile >> N;

    if (N <= 0) {
        cout << "Invalid matrix size. Matrix must be a positive integer." << endl;
        inputFile.close();
        return false;
    }

    matrix1.resize(N, std::vector<int>(N));
    matrix2.resize(N, std::vector<int>(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!(inputFile >> matrix1[i][j])) {
                cout << "File does not contain enough data" << endl;
                inputFile.close();
                return false;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!(inputFile >> matrix2[i][j])) {
                cout << "File does not contain enough data" << endl;
                inputFile.close();
                return false;
            }
        }
    }

    inputFile.close();

    printMatrix(matrix1);
    cout << endl;
    printMatrix(matrix2);
    cout << endl;
    
    return true;
}

bool addMatrices(std::vector<std::vector<int> >& matrix1, std::vector<std::vector<int> >& matrix2) {
    int N = matrix1.size();
    if (N == matrix2.size()) {
        std::vector<std::vector<int> > matrix3(N, std::vector<int>(N));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        printMatrix(matrix3);
        cout << endl;
        return true;
    }
    else {
        return false;
    }
}

void multiplyMatrices(std::vector<std::vector<int> >& matrix1, std::vector<std::vector<int> >& matrix2) {
    int N = matrix1[0].size();
    if (N == matrix2.size()) {
        int rows1 = matrix1.size();
        int cols2 = matrix2[0].size();
        std::vector<std::vector<int> > matrix3(rows1, std::vector<int>(cols2));
        for (int i = 0; i < rows1; ++i) {
            for (int j = 0; j < cols2; ++j) {
                for (int k = 0; k < N; ++k) {
                    matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
        printMatrix(matrix3);
        cout << endl;
    }
    else {
        cout << "The two matrices provided can't be multiplied" << endl;
    }
}

void diagonalSumMatrix(std::vector<std::vector<int> >& matrix1) {
    int N = matrix1.size();
    int main_diagonal = 0;
    for (int i = 0; i < N; ++i) {
        main_diagonal += matrix1[i][i];
    }
    int sec_diagonal = 0;
    for (int i = N - 1; i > -1; --i) {
        sec_diagonal += matrix1[3-i][i];
    }
    cout << "Main Diagonal: " << main_diagonal << endl;
    cout << "Secondary Diagonal: " << sec_diagonal << endl;
    cout << endl;
}

void swapRowsMatrix(std::vector<std::vector<int> >& matrix, int row1, int row2) {
    if (row1 < matrix.size() && row1 > -1 && row2 < matrix.size() && row2 > -1) {
        std::vector<std::vector<int> > new_matrix = matrix;
        new_matrix[row1] = matrix[row2];
        new_matrix[row2] = matrix[row1];
        printMatrix(new_matrix);
        cout << endl;
    }
    else {
        cout << "Invalid rows entered, make sure you are entering the row indices" << endl;
    }
}

void swapColsMatrix(std::vector<std::vector<int> >& matrix, int col1, int col2) {
    if (-1 < col1 < matrix[0].size() && -1 < col2 < matrix[0].size()) {
        std::vector<std::vector<int> > new_matrix = matrix;
        for (int i = 0; i < matrix[0].size(); ++i) {
            new_matrix[i][col1] = matrix[i][col2];
            new_matrix[i][col2] = matrix[i][col1];
        }
        printMatrix(new_matrix);
        cout << endl;
    }
    else {
        cout << "Invalid column entered, make sure you are entering the column indices" << endl;
    }
}

void changeEntryMatrix(std::vector<std::vector<int> >& matrix, int row, int col, int new_value) {
    if (-1 < row < matrix.size() && -1 < col < matrix[0].size()) {
        std::vector<std::vector<int> > new_matrix = matrix;
        new_matrix[row][col] = new_value;
        printMatrix(new_matrix);
        cout << endl;
    }
    else {
        cout << "Invalid indice entered, make sure you are entering the indices starting at zero." << endl;
    }
}

int main() {
    string filename;
    cout << "Enter the filenmae: ";
    cin >> filename;

    std::vector<std::vector<int> > matrixA, matrixB;

    loadMartices(filename, matrixA, matrixB);

    cout << "Adding A and B\n" << endl;
    addMatrices(matrixA, matrixB);

    cout << "Multiplying A and B\n" << endl;
    multiplyMatrices(matrixA, matrixB);

    cout << "Sum of diagonal elements in A\n" << endl;
    diagonalSumMatrix(matrixA);

    cout << "Swap matrix rows in A\n" << endl;
    int row1 = 0;
    int row2 = 0;
    cout << "Enter the first row index: ";
    cin >> row1;
    cout << "Enter the second row index: ";
    cin >> row2;
    swapRowsMatrix(matrixA, row1, row2);

    cout << "Swap matrix columns in A\n" << endl;
    int col1 = 0;
    int col2 = 0;
    cout << "Enter the first column index: ";
    cin >> col1;
    cout << "Enter the second column index: ";
    cin >> col2;
    swapColsMatrix(matrixA, col1, col2);

    cout << "Change entry in A\n" << endl;
    int row = 0;
    int col = 0;
    int new_value = 0;
    cout << "Enter the row index: ";
    cin >> row;
    cout << "Enter the column index: ";
    cin >> col;
    cout << "Enter the new value: ";
    cin >> new_value;
    changeEntryMatrix(matrixA, row, col, new_value);
}