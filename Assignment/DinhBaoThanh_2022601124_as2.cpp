/*ThanhDB 10/10/23 06:42:44*/

#include <iostream>
#include <string.h>

using namespace std;

class NGUOI {
	private:
	    char HoTen[100];
	    char NgaySinh[20];
	    char QueQuan[100];
	
	public:
	    void Nhap();
	    void Xuat();
};

class SINHVIEN: public NGUOI {
	private:
	    char MaSv[20];
	    char Nganh[100];
	    int KhoaHoc;
	
	public:
	    void Nhap();
	    void Xuat();
	    friend class LOPHOC;
};

class LOPHOC {
	private:
	    char MaLH[20];
	    char TenLH[100];
	    char NgayMo[20];
	    SINHVIEN x[100]; 
	    int n; 
	
	public:
	    void Nhap();
	    void Xuat();
	    int CountSV();
	    void SortKH();
};

void NGUOI::Nhap() {
	
    cout << "Nhap Ho Ten: ";	fflush(stdin);	gets(HoTen);
    cout << "Nhap Ngay Sinh: ";	fflush(stdin);	gets(NgaySinh);
    cout << "Nhap Que Quan: ";	fflush(stdin);	gets(QueQuan);
}

void NGUOI::Xuat() {
	
    cout << "Ho Ten: " << HoTen << endl;
    cout << "Ngay Sinh: " << NgaySinh << endl;
    cout << "Que Quan: " << QueQuan << endl;
}

void SINHVIEN::Nhap() {
	
    NGUOI::Nhap();
    cout << "Nhap Ma Sinh Vien: ";	fflush(stdin);	gets(MaSv);
    cout << "Nhap Nganh: ";			fflush(stdin);	gets(Nganh);
	cout << "Nhap Khoa Hoc: ";						cin >> KhoaHoc;
}

void SINHVIEN::Xuat() {
	
    NGUOI::Xuat();
    cout << "Ma Sinh Vien: " << MaSv << endl;
    cout << "Nganh: " << Nganh << endl;
    cout << "Khoa Hoc: " << KhoaHoc << endl;
}

void LOPHOC::Nhap() {
    cout << "Nhap Ma Lop Hoc: ";	fflush(stdin);	gets(MaLH);
    cout << "Nhap Ten Lop Hoc: ";	fflush(stdin);	gets(TenLH);
    cout << "Nhap Ngay Mo Lop: ";	fflush(stdin);	gets(NgayMo);

    cout << "Nhap so sinh vien trong lop: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        x[i].Nhap();
    }
}

void LOPHOC::Xuat() {
    cout << "Ma Lop Hoc: " << MaLH << endl;
    cout << "Ten Lop Hoc: " << TenLH << endl;
    cout << "Ngay Mo Lop: " << NgayMo << endl;
    cout << "Danh Sach Sinh Vien trong Lop:" << endl;
    for (int i = 0; i < n; i++) {
        x[i].Xuat();
        cout << "---------------------" << endl;
    }
}

int LOPHOC::CountSV() {
	
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (x[i].KhoaHoc == 11) {
            count++;
        }
    }
    return count;
}

void LOPHOC::SortKH() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (x[i].KhoaHoc > x[j].KhoaHoc) {
                swap(x[i], x[j]);
            }
        }
    }
}

int main() {
	
    LOPHOC a;
    a.Nhap();
    cout << "Thong tin lop hoc: " << endl;
    a.Xuat();

    int svk11 = a.CountSV();
    cout<<"--------------------------------------"<<endl;
    cout << "So sinh vien khoa 11: " << svk11 << endl;
	
    a.SortKH();
    cout<<"--------------------------------------"<<endl;
    cout << "Danh sach lop hoc sau khi sap xep theo khoa hoc: " << endl;
    a.Xuat();

    return 0;
}

