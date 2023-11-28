#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
class tamgiac
{
    private:
        float a,b,c;
    public:
        double operator!();
        friend istream& operator>> (istream& in, tamgiac &a);
        friend ostream& operator<< (ostream& out, tamgiac a);
};
istream& operator>> (istream& in, tamgiac &a)
{
    cin>>a.a>>a.b>>a.c;
    return in;
}
double tamgiac::operator!()
{
    return a+b+c;
}
ostream& operator<< (ostream& out, tamgiac a)
{
    out << "\nBa canh cua tam giac la : "  << a.a << "\t" << a.b << "\t" << a.c << endl;
    out << "Chu vi cua tam giac la: " << a.a+a.b+a.c;
    return out;
}

int main()
{
    tamgiac p,q;
    cout << "Nhap cac canh cua tam giac p " << endl;
    cin>>p;
    cout << "Nhap cac canh cua tam giac q " << endl;
    cin>>q;
    cout << p;
    cout << q;
    ofstream ghi("INOUT.txt", ios::out);
    ghi<< p;
    ghi<<q;
    return 0;
}

