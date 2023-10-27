#include <iostream>
#include <fstream>

using namespace std;

class PhanSo {
private:
    int TuSo;
    int MauSo;

public:

    PhanSo(int tu = 0, int mau = 1) : TuSo(tu), MauSo(mau) {}


    PhanSo operator*(const PhanSo& other) {
        return PhanSo(TuSo * other.TuSo, MauSo * other.MauSo);
    }


    float getValue() {
        return (TuSo / MauSo);
    }


    friend istream& operator>>(istream& is, PhanSo& phanso) {
        cout << "Nhap tu so: ";
        is >> phanso.TuSo;
        cout << "Nhap mau so: ";
        is >> phanso.MauSo;
        return is;
    }


    friend ostream& operator<<(ostream& os, const PhanSo& phanso) {
        os << phanso.TuSo << "/" << phanso.MauSo;
        return os;
    }
};

int main() {
    PhanSo phanSo1, phanSo2, ketQua;

    cout << "Nhap phan so thu nhat:\n";
    cin >> phanSo1;

    cout << "Nhap phan so thu hai:\n";
    cin >> phanSo2;

    ketQua = phanSo1 * phanSo2;

    cout << "Tich cua hai phan so la: " << ketQua << endl;


    ofstream outFile("PHANSO.txt");
    if (outFile.is_open()) {
        outFile << "Ket qua: " << ketQua << endl;
        outFile.close();
        cout << "Ket qua da duoc ghi vao PHANSO.txt\n";
    } else {
        cerr << "Khong the mo file PHANSO.txt de ghi ket qua.\n";
    }

    return 0;
}

