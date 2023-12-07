#include <iostream>
#include <fstream>

using namespace std;

class TamGiac {
private:
    float a, b, c;

public:

    friend istream &operator>>(istream &is, TamGiac &tamGiac);
    friend ostream &operator<<(ostream &os, const TamGiac &tamGiac);
    float operator++() const {
        return a + b + c;
    }
    
};

istream &operator>>(istream &is, TamGiac &tamGiac) {
        cout << "Nhap canh a: ";
        is >> tamGiac.a;
        cout << "Nhap canh b: ";
        is >> tamGiac.b;
        cout << "Nhap canh c: ";
        is >> tamGiac.c;
        return is;
}


ostream &operator<<(ostream &os, const TamGiac &tamGiac) {
        os << "Tam giac co cac canh la a = " << tamGiac.a << ", b = " << tamGiac.b << ", c = " << tamGiac.c << "\n";
        os << "Chu vi tam giac: " << ++tamGiac << "\n";
        return os;
}



int main() {
    TamGiac P, Q;

    cout << "Nhap thong tin tam giac P:\n";
    cin >> P;

    cout << "Nhap thong tin tam giac Q:\n";
    cin >> Q;

    cout << "Thong tin tam giac P:\n" << P;
    cout << "Thong tin tam giac Q:\n" << Q;

    ofstream outFile("INOUT.txt");
    if (outFile.is_open()) {
        outFile << "Thong tin tam giac P:\n" << P;
        outFile << "Thong tin tam giac Q:\n" << Q;
        outFile.close();
        cout << "Da ghi vao file INOUT.txt.\n";
    } else {
        cerr << "Khong the mo file de ghi.\n";
    }

    return 0;
}

