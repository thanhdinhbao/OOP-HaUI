#include <iostream>
#include <iomanip>
using namespace std;

class phieu;
class Ncc
{
private:
    char maNcc[10];
    char tenNcc[20];
    char diachi[30];
    char sodienthoai[10];
public:
    void nhap();
    void xuat();
};
void Ncc::nhap()
{
    cout << "Nhap ma nha cung cap: ";                   fflush(stdin);          gets(maNcc);
    cout << "Nhap ten nha cung cap: ";                  fflush(stdin);          gets(tenNcc);
    cout <<  "Nhap dia chi: ";                          fflush(stdin);          gets(diachi);
    cout  << "Nhap so dien thoai: ";                    fflush(stdin);          gets(sodienthoai);
}
void Ncc::xuat()
{
    cout <<setw(18)<< "Ma nha cung cap: "<<maNcc;
    cout <<setw(30)<<"Ten nha cung cap: "<<tenNcc<<endl;
    cout <<setw(10) <<"Dia chi: "<<diachi;
    cout << setw(10)<<"SDT: "<<sodienthoai<<endl;
}

class sanpham
{
private:
    char masp[5];
    char tensp[20];
    int soluong;
    int dongia;
public:
    void nhap();
    void xuat();
    friend class phieu;
    friend int dem(phieu c);
    friend void sapxep(phieu &s);
};
void sanpham::nhap()
{
    cout << "Nhap ma san pham: ";                     fflush(stdin);          gets(masp);
    cout << "Nhap ten san pham: ";                    fflush(stdin);          gets(tensp);
    cout << "Nhap so luong: ";                                                cin >> soluong;
    cout << "Nhap don gia: ";                                                 cin >> dongia;
}
void sanpham::xuat()
{
    cout << setw(5) << masp;
    cout << setw(20) <<tensp;
    cout << setw(15) << soluong;
    cout << setw(10)<< dongia;
    cout << setw(10) <<dongia*soluong<<endl;
}

class phieu
{
private:
    char maphieu[10];
    char ngay[20];
    Ncc x;
    sanpham y[10];
    int n;
public:
    void nhap();
    void xuat();
    friend int dem(phieu c);
    friend void sapxep(phieu &s);
};
void phieu::nhap()
{
    cout << "Nhap ma phieu: ";                      fflush(stdin);          gets(maphieu);
    cout << "Nhap ngay lap phieu: ";                fflush(stdin);          gets(ngay);
    x.nhap();
    cout << "Nhap so loai san pham: ";                                      cin >> n;
    for(int i = 0; i < n; i++)
        y[i].nhap();
}
void phieu::xuat()
{
    int tong = 0;

    cout << "Dai hoc Victory"<<endl;
    cout << "\t\tPHIEU NHAP VAN PHONG PHAM"<<endl;
    cout << setw(11)<<"Ma phieu: "<<maphieu;
    cout << setw(29)<< "Ngay lap: "<<ngay<<endl;
    x.xuat();
    cout << setw(6) << "Ma SP";
    cout << setw(20) <<"Ten san pham";
    cout << setw(15) << "So luong";
    cout << setw(10)<< "Don gia";
    cout << setw(15) <<"Thanh tien"<<endl;
    for(int i = 0; i < n; i++)
    {
        y[i].xuat();
        int p = y[i].soluong*y[i].dongia;
        tong += p;
    }
    cout << setw(30) << "TONG" << setw(30) << tong<<endl;
    cout << setw(15) << "Hieu truong";
    cout << setw(20) << "Phong tai chinh";
    cout << setw(15) << "Nguoi lap"<<endl;
}
int dem(phieu c)
{
    int dem = 0;
    for(int i = 0; i < c.n; i++)
    {
        if(c.y[i].soluong < 80)
            dem++;
    }
    return dem;
}
void sapxep(phieu &s)
{
    for(int i = 0 ; i < s.n-1; i++)
        for(int j = i + 1; j < s.n; j++)
        {
            if(s.y[i].dongia < s.y[j].dongia)
            {
                sanpham tmp = s.y[i];
                s.y[i] = s.y[j];
                s.y[j] = tmp;
            }
        }
}

///////////////////////////////////////////////////////////////
int main()
{
    phieu a;
    a.nhap();
    cout << "\n--------------------------------------------------"<<endl;
    a.xuat();
    cout << "-------------------------------------------------------"<<endl;
    int k = dem(a);
    cout << "So san pham co so luong nhap nho hon 80 la: " << k<<endl;
    sapxep(a);
    cout << "-------------------------------------------------------"<<endl;
    cout << "Phieu sau khi sap xep lai: "<<endl;
    a.xuat();
    cout << "-------------------------------------------------------"<<endl;
    return 0;
}
