#include <iostream>
using namespace std;

template <class T>
class matrix {
private:
    T a[20][20];
    int n, m;

public:
    template <class U>
    friend istream& operator>>(istream& in, matrix<U>& x);
    template <class U>
    friend ostream& operator<<(ostream& out, matrix<U> x);
    matrix<T> operator!();
};
 template<class U> istream& operator>>(istream& in, matrix<U>& x) {
        cout << "Nhap vao so dong cua ma tran: ";
        in >> x.n;
        cout << "Nhap vao so cot cua ma tran: ";
        in >> x.m;

        for (int i = 0; i < x.n; i++) {
            for (int j = 0; j < x.m; j++) {
                cout << "a[" << i << "][" << j << "] = ";
                in >> x.a[i][j];
            }
        }
        return in;
    }
template<class U> ostream& operator<<(ostream& out, matrix<U> x) {
        for (int i = 0; i < x.n; i++) {
            for (int j = 0; j < x.m; j++) {
                out << x.a[i][j] << " ";
            }
            out << endl;
        }
        return out;
    }
template<class T> matrix<T> matrix<T>::operator!() {
        matrix<T> hv;
        hv.n = m;
        hv.m = n;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                hv.a[j][i] = a[i][j];
            }
        }

        return hv;
    }
int main() {
    matrix<double> a;
    cin >> a;
    cout << "Ma tran 1 (double): " << endl;
    cout << a;
    a = !a;
    cout << "Ma tran 1 sau khi chuyen vi: " << endl;
    cout << a;
    matrix<long> b;
    cin >> b;
    cout << "Ma tran 2 (long): " << endl;
    cout << b;

    b = !b;
    cout << "Ma tran 2 sau khi chuyen vi: " << endl;
    cout << b;

    return 0;
}

