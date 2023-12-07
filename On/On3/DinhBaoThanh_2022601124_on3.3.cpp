#include <iostream>

template <typename T>
class Matrix {
private:
    T** data;
    int rows;
    int cols;

public:
    Matrix(int numRows, int numCols) : rows(numRows), cols(numCols) {
        // C?p ph�t b? nh? cho ma tr?n
        data = new T*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new T[cols];
        }
    }

    ~Matrix() {
        // Gi?i ph�ng b? nh? khi d?i tu?ng b? h?y
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    // Phuong th?c nh?p ma tr?n t? b�n ph�m
    void inputMatrix() {
        std::cout << "Nhap ma tran " << rows << "x" << cols << ":\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << "Nhap phan tu thu [" << i + 1 << "][" << j + 1 << "]: ";
                std::cin >> data[i][j];
            }
        }
    }

    // Phuong th?c xu?t ma tr?n ra m�n h�nh
    void outputMatrix() const {
        std::cout << "Ma tran " << rows << "x" << cols << ":\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

    // Phuong th?c chuy?n v? ma tr?n
    Matrix<T> transpose() const {
        Matrix<T> result(cols, rows);
        for (int i = 0; i < cols; ++i) {
            for (int j = 0; j < rows; ++j) {
                result.data[i][j] = data[j][i];
            }
        }
        return result;
    }
};

int main() {
    int numRows, numCols;

    // Nh?p k�ch thu?c ma tr?n ki?u th?c
    std::cout << "Nhap so dong cua ma tran ki?u th?c: ";
    std::cin >> numRows;
    std::cout << "Nhap so cot cua ma tran ki?u th?c: ";
    std::cin >> numCols;

    // T?o v� nh?p ma tr?n ki?u th?c
    Matrix<double> doubleMatrix(numRows, numCols);
    doubleMatrix.inputMatrix();

    // Xu?t ma tr?n ki?u th?c
    doubleMatrix.outputMatrix();

    // Nh?p k�ch thu?c ma tr?n ki?u nguy�n
    std::cout << "Nhap so dong cua ma tran ki?u nguy�n: ";
    std::cin >> numRows;
    std::cout << "Nhap so cot cua ma tran ki?u nguy�n: ";
    std::cin >> numCols;

    // T?o v� nh?p ma tr?n ki?u nguy�n
    Matrix<long> intMatrix(numRows, numCols);
    intMatrix.inputMatrix();

    // Xu?t ma tr?n ki?u nguy�n
    intMatrix.outputMatrix();

    // Chuy?n v? v� xu?t ma tr?n ki?u th?c
    Matrix<double> transposedDoubleMatrix = doubleMatrix.transpose();
    std::cout << "Ma tran ki?u th?c sau khi chuyen vi:\n";
    transposedDoubleMatrix.outputMatrix();

    // Chuy?n v? v� xu?t ma tr?n ki?u nguy�n
    Matrix<long> transposedIntMatrix = intMatrix.transpose();
    std::cout << "Ma tran ki?u nguy�n sau khi chuyen vi:\n";
    transposedIntMatrix.outputMatrix();

    return 0;
}

