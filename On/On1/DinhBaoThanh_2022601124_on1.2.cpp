
#include <iostream>
#include <iomanip>
using namespace std;

class phieu;


class sinhvien
{
private:
    char masv[10];
    char tensv[20];
    char lop[10];
    int khoa;
public:
    void nhap();
    void xuat();

};

void sinhvien::nhap()
{
    cout << "Nhap ma sinh vien: ";          fflush(stdin);          gets(masv);
    cout << "Nhap ten sinh vien: ";         fflush(stdin);          gets(tensv);
    cout << "Nhap ten lop: ";               fflush(stdin);          gets(lop);
    cout << "Nhap khoa: ";                                          cin >> khoa;
}

void sinhvien::xuat()
{
    cout << setw(15)<<" Ma sinh vien: " << masv;
    cout << setw(20)<<"Ten sinh vien: " << tensv << endl;
    cout << setw(6)<<"Lop:\t" << lop;
    cout <<  setw(15)<< "Khoa: " << khoa << endl;

}

class monhoc
{
private:
    char tenmon[20];
    int sotrinh;
    float diem;
public:
    void nhap();
    void xuat();
    friend class phieu;
    friend void lonhon3(phieu z);

};
void monhoc::nhap()
{
    cout << "Nhap ten mon hoc: ";           fflush(stdin);      gets(tenmon);
    cout << "Nhap so trinh: ";                                  cin >> sotrinh;
    cout << "Nhap diem: ";                                      cin >> diem;
}
void monhoc::xuat()
{
    cout << setw(15) <<tenmon;
    cout << setw(15) <<sotrinh;
    cout << setw(15) <<diem <<endl;
}


class phieu
{
private:
    sinhvien x;
    monhoc y[20];
    int n;
public:
    void nhap();
    void xuat();
    void chen();
    friend void lonhon3(phieu z);
};

void phieu::nhap()
{
    x.nhap();
    cout << "Nhap so luong mon hoc: ";                           cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        y[i].nhap();
    }
}
void phieu::xuat()
{
    float p = 0, s = 0;

    x.xuat();
    cout << "Bang diem:" <<endl;
    cout << setw(15) << "Ten mon";
    cout << setw(15) << "So trinh";
    cout << setw(15) << "Diem" <<endl;
    for(int i = 0 ; i < n ; i++)
    {
        y[i].xuat();
        p += y[i].sotrinh;
        s += y[i].sotrinh*y[i].diem;
    }
    float diemtb = s / p;
    cout << setw(35) << "Diem trung binh: "  <<setprecision(2)<<setw(9)<<diemtb<<endl;
}

void lonhon3(phieu z)
{
    for(int i = 0; i < z.n ; i++)
    {

        if(z.y[i].sotrinh > 3)
        {
            cout << setw(15)<< z.y[i].tenmon<<endl;
        }
    }
}

void phieu::chen()
{
    if (n < 20)
    {
        y[n].nhap();
        n++;
    }
    else
    {
        cout << "Danh sach mon hoc da day, khong the them mon hoc moi." << endl;
    }
}



int main()
{
    phieu a;
    a.nhap();
    cout << "\n";
    cout << "------------------------------------------" << endl;
    cout <<  setw(20) <<  "\t\tPHIEU BAO DIEM " << endl;
    a.xuat();
    cout << "------------------------------------------" << endl;
    cout << "Bonus 1: Cac mon hoc co so trinh lon hon 3 "<< endl;
    lonhon3(a);
    cout << "------------------------------------------" << endl;

    cout << "Bonus 2: chen mon hoc"<<endl;
    a.chen();
    cout << "\n Phieu bao diem sau khi chen: "<<endl;
    a.xuat();
    cout << "------------------------------------------" << endl;
    return 0;
}

