#include <iostream>

using namespace std;

class ARRAY {
private:
    int* VALUE;
    int n;

public:

    ARRAY() : n(0), VALUE(0) {}


    ARRAY(int size) : n(size) {
        VALUE = new int[n];
        for (int i = 0; i < n; i++) {
            VALUE[i] = 0;
        }
    }


    ~ARRAY() {
        n = 0;
        delete[] VALUE;
    }


    void NHAP() {
        if (VALUE != 0) {
            cout << "Nhap gia tri cho mang:" << endl;
            for (int i = 0; i < n; i++) {
                cout << "a[" << i << "]: ";
                cin >> VALUE[i];
            }
        }
    }


    void XUAT() {
        cout << "Mang a: ";
        if (VALUE != 0) {
            for (int i = 0; i < n; i++) {
                cout << VALUE[i] << " ";
            }
        }
        cout << endl;
    }
};

int main() {

    ARRAY a1;

    cout << "Mang a1:" << endl;
    a1.XUAT();


    int size;
    cout << "Nhap s? lu?ng ph?n t? c?a m?ng: ";
    cin >> size;
    ARRAY a2(size);

    cout << "M?ng a2 sau khi kh?i t?o:" << endl;
    a2.XUAT();

    // Nh?p giá tr? cho m?ng a2
    a2.NHAP();

    cout << "M?ng a2 sau khi nh?p giá tr?:" << endl;
    a2.XUAT();

    return 0;
}

