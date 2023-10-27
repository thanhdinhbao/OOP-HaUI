#include <iostream>
#include <iomanip>

using namespace std;
class phieunhaphang;

class NCC
{
private:
    char mancc[10];
    char tenncc[30];
    char diachi[50];
public:
    void nhap();
    void xuat();

};
void NCC::nhap()
{
    cout << "Nhap ma NCC: ";                fflush(stdin);          gets(mancc);
    cout << "Nhap ten NCC: ";               fflush(stdin);          gets(tenncc);
    cout << "Nhap dia chi: " ;              fflush(stdin);          gets(diachi);
}

void NCC::xuat()
{
    cout << setw(9) <<"Ma NCC: " << mancc;
    cout << setw(20) << "Ten NCC: " << tenncc<< endl;
    cout << setw(10) << "Dia chi: " << diachi<< endl;
}

class Hang
{
private:
    char tenhang[20];
    float dongia;
    int soluong;
public:
    void nhap();
    void xuat();
    friend class phieunhaphang;
};

void Hang::nhap()
{
    cout << "Nhap ten hang: ";              fflush(stdin);      gets(tenhang);
    cout << "Nhap don gia: ";                                   cin >> dongia;
    cout << "Nhap so luong: ";                                  cin >> soluong;
}

void Hang::xuat()
{
    cout  <<setw(9)<< tenhang;
    cout << setw(15)<<dongia;
    cout  <<setw(15)<<soluong;
    cout  <<setw(15)<<dongia*soluong<< endl;
}

class phieunhaphang
{
private:
    char maphieu[10];
    char ngay[20];
    NCC x;
    Hang y[10];
    int n;
public:
    void nhap();
    void xuat();

};

void phieunhaphang::nhap()
{
    float a = 0;

    cout << "Nhap ma phieu: ";             fflush(stdin);      gets(maphieu);
    cout << "Nhap ngay: ";                 fflush(stdin);      gets(ngay);
    x.nhap();
    cout << "Nhap vao so loai hang: ";                         cin >> n;
    for(int i = 0; i < n; i++)
        y[i].nhap();
}

void phieunhaphang::xuat()
{
    float tong = 0;

    cout << setw(11) << "Ma phieu: " << maphieu;
    cout << setw(20) << "Ngay lap: " << ngay << endl;
    x.xuat();
    cout << setw(9) << "Ten hang";
    cout << setw(15) << "Don gia";
    cout << setw(15) << "So luong";
    cout << setw(15) << "Thanh tien" << endl;
    for( int i = 0; i < n; i++)
    {
        y[i].xuat();

        float p = y[i].dongia*y[i].soluong;
        tong += p;
    }
    cout << setw(45)<< " Cong thanh tien :" << setw(9)<<tong<<endl;
}



main()
{
    phieunhaphang a;
    a.nhap();
    cout << "\n";
    cout << "------------------------------------------" << endl;
    cout <<  setw(20) <<  "\t\tPHIEU NHAP HANG " << endl;
    a.xuat();
    cout << "------------------------------------------" << endl;
    return 0;

}
