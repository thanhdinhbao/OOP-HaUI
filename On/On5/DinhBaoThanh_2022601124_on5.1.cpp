#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class array {
	private:
    	float *value;
    	int n;
	public:
    	friend istream& operator>> (istream& in, array &x);
    	friend ostream& operator<< (ostream& out, array x);
    	array operator++();
    	array operator--();
};

istream& operator>> (istream& in, array &x) {
    cout << "So luong phan tu co trong mang: ";
    in >> x.n;
    x.value = new float[x.n];
    for (int i = 0; i < x.n; i++) {
        cout << "value[" << i << "] = ";
        in >> x.value[i];
    }
    return in;
}

ostream& operator<< (ostream& out, array x) {
    for (int i = 0; i < x.n; i++)
        out << setw(5) << x.value[i];
    return out;
}

array array::operator++() {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (value[i] > value[j]) {
                float tmp = value[i];
                value[i] = value[j];
                value[j] = tmp;
            }
    return *this;
}

array array::operator--() {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (value[i] < value[j]) {
                float tmp = value[i];
                value[i] = value[j];
                value[j] = tmp;
            }
    return *this;
}

int main() {
    array a;
    cin >> a;
    cout << "Gia tri cac phan tu cua mang" << endl;
    cout << a << endl;

    a=++a;
    cout << "Gia tri cac phan tu cua mang tang dan" << endl;
    cout << a << endl;
    a=--a;
    cout << "Gia tri cac phan tu cua mang giam dan" << endl;
    cout << a << endl;
    ofstream ghi("MANG.txt", ios::out);
    a=++a;
    ghi << "Gia tri cac phan tu cua mang tang dan" << endl;
    ghi << a << endl;
    a=--a;
    ghi << "Gia tri cac phan tu cua mang giam dan" << endl;
    ghi << a << endl;
    return 0;
}

