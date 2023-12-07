#include <iostream>
#include <fstream>

using namespace std;

class Mang {
private:
    float VALUE[100]; 
    int n;

public:
    friend istream &operator>>(istream &is, Mang &arr);
    friend ostream &operator<<(ostream &os, const Mang &arr);
    Mang operator++();
    Mang operator--();
    void ghiFile();
};

istream &operator>>(istream &is, Mang &arr) {
        cout << "Nhap kich thuoc mang n: ";
        is >> arr.n;

        cout << "Nhap gia tri cho mang:\n";
        for (int i = 0; i < arr.n; ++i) {
            cout << "Nhap gia tri thu " << i + 1 << ": ";
            is >> arr.VALUE[i];
        }

        return is;
}

ostream &operator<<(ostream &os, const Mang &arr) {
        os << "Cac gia tri cua mang la:\n";
        for (int i = 0; i < arr.n; ++i) {
            os << arr.VALUE[i] << " ";
        }
        os << "\n";

        return os;
}

Mang Mang::operator++(){
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (VALUE[i] > VALUE[j]) {
                    // Hoan doi gia tri
                    float temp = VALUE[i];
                    VALUE[i] = VALUE[j];
                    VALUE[j] = temp;
                }
            }
        }

        return *this;
}

Mang Mang::operator--() {
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (VALUE[i] < VALUE[j]) {
                    // Hoan doi gia tri
                    float temp = VALUE[i];
                    VALUE[i] = VALUE[j];
                    VALUE[j] = temp;
                }
            }
        }

        return *this; 
}

void Mang::ghiFile(){
	    ofstream outFile("MANG.txt");
        if (outFile.is_open()) {
            outFile << "Mang sau khi sap xep tang dan:\n";
            for (int i = 0; i < n; ++i) {
                outFile << VALUE[i] << " ";
            }
            outFile << "\n";

            outFile << "Mang sau khi sap xep giam dan:\n";
            for (int i = 0; i < n; ++i) {
                outFile << VALUE[i] << " ";
            }
            outFile << "\n";

            outFile.close();
            cout << "Da ghi vao file MANG.txt.\n";
        } else {
            cerr << "Khong the mo file de ghi.\n";
        }
}

int main() {
    Mang mang;
    
    cin >> mang;
    
   	++mang;
    cout << "Mang sau khi sap xep tang dan:\n" << mang;
	mang.ghiFile();
	
    --mang;
    cout << "Mang sau khi sap xep giam dan:\n" << mang;
    mang.ghiFile();

    return 0;
}

