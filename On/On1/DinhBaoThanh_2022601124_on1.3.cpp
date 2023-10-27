#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;


class phieu;
///////////////////////////////////
class nhanvien
{
private:
    char ten[20];
    char chucvu[20];
public:
    void nhap();
    void xuat();
};
void nhanvien::nhap()
{
    cout << "Nhap ten nhan vien kiem ke: ";            fflush(stdin);       gets(ten);
    cout << "Nhap chuc vu cua nhan vien: ";            fflush(stdin);       gets(chucvu);
}

void nhanvien::xuat()
{
    cout << setw(20) <<"Nhan vien kiem ke: " << ten;
    cout << setw(18)<<"Chuc vu: " << chucvu<<endl;
}

///////////////////////////////////////////////////////////////////
class phongban
{
private:
    char tenphong[20];
    char maphong[10];
    char truongphong[20];
public:
    void nhap();
    void xuat();

};
void phongban::nhap()
{
    cout << "Nhap ten phong: ";                     fflush(stdin);          gets(tenphong);
    cout << "Nhap ma phong: ";                      fflush(stdin);          gets(maphong);
    cout << "Nhap ten truong phong: ";              fflush(stdin);          gets(truongphong);
}
void phongban::xuat()
{
    cout << setw(20)<< "Kiem ke tai phong: " << tenphong;
    cout <<setw(15) <<"Ma phong: " << maphong<<endl;
    cout << setw(15) <<"Truong phong: " << truongphong << endl;
}


////////////////////////////////////////////////////////////
class taisan
{
private:
    char tents[20];
    int soluong;
    char tinhtrang[20];
public:
    void nhap();
    void xuat();
    friend class phieu;
    friend void suatt(phieu &s);
    friend void sapxep(phieu &sx);

};
void taisan::nhap()
{
    cout << "Nhap vao ten tai san: ";              fflush(stdin);           gets(tents);
    cout << "Nhap so luong: ";                                              cin >> soluong;
    cout << "Nhap tinh trang tai san: ";           fflush(stdin);           gets(tinhtrang);
}
void taisan::xuat()
{
    cout <<setw(15) << tents;
    cout  <<setw(15)<< soluong;
    cout  <<setw(20)<< tinhtrang<<endl;
}

/////////////////////////////////////////////////////////////////
class phieu
{
private:
    char maphieu[10];
    char ngay[20];
    nhanvien x;
    phongban y;
    taisan z[10];
    int n;
public:
    void nhap();
    void xuat();
    friend void suatt(phieu &s);
    friend void sapxep(phieu &sx);

};
void phieu::nhap()
{
    cout << "Nhap ma phieu: ";                      fflush(stdin);          gets(maphieu);
    cout << "Nhap ngay kiem ke: ";                  fflush(stdin);          gets(ngay);
    x.nhap();
    y.nhap();
    cout << "Nhap so loai tai san: ";                                       cin >> n;
    for(int i = 0 ; i < n; i++)
    {
        z[i].nhap();
    }
}
void phieu::xuat()
{
    int p = 0;
    cout << setw(40) << "PHIEU KIEM KE TAI SAN"<< endl;
    cout << setw(11) << "Ma phieu: " <<maphieu;
    cout <<setw(42) << "Ngay kiem ke: "<<ngay<<endl;
    x.xuat();
    y.xuat();
    cout <<setw(15) <<"Ten tai san";
    cout  <<setw(15)<< "So luong";
    cout  <<setw(15)<< "Tinh trang"<<endl;
    for(int i = 0 ; i < n; i++)
    {
        z[i].xuat();
        p += z[i].soluong;
    }
    cout <<setw(24)<< "So tai san da kiem ke: " << n;
    cout <<setw(20)<< "Tong so luong: " << p<<endl;

}
void suatt(phieu &s)
{
    for(int i = 0; i < s.n; i++)
    {
        if(strcmp(s.z[i].tents, "may vi tinh") == 0)
            s.z[i].soluong = 20;
    }
}
void sapxep(phieu &sx)
{
    for(int i = 0; i < sx.n-1; i++)
        for(int j = i+1; j < sx.n; j++)
        {
            if(sx.z[i].soluong > sx.z[j].soluong )
            {
                taisan tmp  = sx.z[i];
                    sx.z[i] = sx.z[j];
                    sx.z[j] = tmp;

            }

        }
}
////////////////////////////////////////////////////////////////
int main()
{
    phieu a;
    a.nhap();
    cout << "----------------------------------------------"<<endl;
    a.xuat();
    cout << "----------------------------------------------"<<endl;
    cout << "Bonus 1: Sua thong tin"<<endl;
    suatt(a);
    a.xuat();
    cout << "----------------------------------------------"<<endl;
    cout << "Bonus 2: Sap xep"<<endl;
    sapxep(a);
    a.xuat();
    cout << "----------------------------------------------"<<endl;
    return 0;
}
