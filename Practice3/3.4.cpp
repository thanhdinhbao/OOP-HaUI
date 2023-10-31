#include <iostream>
#include <cmath>

using namespace std;

class PT {
private:
    double a;
    double b;
    double c;

public:
    PT();
    PT(double a, double b, double c);
    void NHAP();
    void XUAT();
    void GIAI();
};

PT ::PT(){
	a=0;
	b=0;
	c=0;
}

PT :: PT(double x, double y, double z){
	a=x;
	b=y;
	c=z;
}

void PT::NHAP(){
	
	cout << "Nhap a: ";		cin >> a;
    cout << "Nhap b: ";		cin >> b;
    cout << "Nhap c: ";		cin >> c;
}

void PT::XUAT(){
	
	        cout << a << "x^2";
        if (b >= 0) {
            cout << "+" << b << "x";
        } else {
            cout << b << "x";
        }
        if (c >= 0) {
            cout << "+" << c;
        } else {
            cout << c;
        }
        cout << "=0" << endl;
}

void PT::GIAI(){
	
	        if (a == 0) {
            if (b == 0) {
                if (c == 0) {
                    cout << "Phuong trinh co vo so nghiem." << endl;
                } else {
                    cout << "Phuong trinh vo nghiem." << endl;
                }
            } else {
                double x = -c / b;
                cout << "Phuong trinh co nghiem duy nhat: x = " << x << endl;
            }
        } else {
            double delta = b * b - 4 * a * c;
            if (delta > 0) {
                double x1 = (-b + sqrt(delta)) / (2 * a);
                double x2 = (-b - sqrt(delta)) / (2 * a);
                cout << "Phuong trinh co 2 nghiem phan biet:" << endl;
                cout << "x1 = " << x1 << endl;
                cout << "x2 = " << x2 << endl;
            } else if (delta == 0) {
                double x = -b / (2 * a);
                cout << "Phuong trinh co nghiem kep: x = " << x << endl;
            } else {
                cout << "Phuong trinh vo nghiem." << endl;
            }
        }
}

int main() {
    cout << "Khoi tao phuong trinh P:" << endl;
    PT P(1, -5, 6); 
    cout << "Phuong trinh P: ";
    P.XUAT();
    P.GIAI();

    cout << "Nhap phuong trinh Q:" << endl;
    PT Q;
    Q.NHAP();
    cout << "Phuong trinh Q: ";
    Q.XUAT();
    Q.GIAI();

    return 0;
}

