//27/10/23 09:50
#include <iostream>
#include <string.h>

using namespace std;

class SinhVien {
	private:
	    char Masv[10];
	    char Hoten[50];
	    float DiemToan;
	    float DiemLy;
	    float DiemHoa;

	public:
	    void nhap();
	    void xuat();
	    float TongDiem();
};

void SinhVien::nhap(){
	
	    cout << "Nhap Ma SV: ";						cin >> Masv;
        cout << "Nhap Ho ten: ";	fflush(stdin); 	gets(Hoten);
        cout << "Nhap Diem Toan: ";					cin >> DiemToan;
        cout << "Nhap Diem Ly: ";					cin >> DiemLy;
        cout << "Nhap Diem Hoa: ";					cin >> DiemHoa;
}

void SinhVien::xuat(){
	
        cout << "Ma SV: " << Masv << endl;
        cout << "Ho ten: " << Hoten << endl;
        cout << "Diem Toan: " << DiemToan << endl;
        cout << "Diem Ly: " << DiemLy << endl;
        cout << "Diem Hoa: " << DiemHoa << endl;
}

float SinhVien::TongDiem(){
	
	return DiemToan + DiemLy + DiemHoa;
}

void sapxep(SinhVien sv[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (sv[j].TongDiem() > sv[j + 1].TongDiem()) {
                SinhVien temp = sv[j];
                sv[j] = sv[j + 1];
                sv[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    SinhVien listSV[n];

    for (int i = 0; i < n; i++) {
        listSV[i].nhap();
    }

    sapxep(listSV, n);
    
	cout << "--------------------------" << endl;
    cout << "Danh sach sinh vien sau khi sap xep theo tong diem:" << endl;
    for (int i = 0; i < n; i++) {
        listSV[i].xuat();
        cout << "Tong Diem: " << listSV[i].TongDiem() << endl;
        cout << "--------------------------" << endl;
    }

    return 0;
}

