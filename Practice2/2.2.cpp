#include <iostream>
#include <cstring>

using namespace std;

class NSX {

	private:
	    int Mansx;
	    char Tennsx[50];
	    char Dcnsx[100];
	public:
	    void nhap();
		void xuat();		

};

void NSX::nhap(){
	
	    cout << "Nhap Ma NSX: ";						cin >> Mansx;
        cout << "Nhap Ten NSX: ";		fflush(stdin); 	gets(Tennsx);
        cout << "Nhap Dia chi NSX: ";	fflush(stdin);	gets(Dcnsx);
}

void NSX::xuat() {
    cout << "Ma NSX: " << Mansx << endl;
    cout << "Ten NSX: " << Tennsx << endl;
    cout << "Dia chi NSX: " << Dcnsx << endl;
}

class HANG {

	private:
	    int Mahang;
	    char Tenhang[50];
	    NSX X;
    public:
	    void nhap();
	    void xuat();
};

void HANG::nhap() {
    cout << "Nhap Ma Hang: ";					cin >> Mahang;
    cout << "Nhap Ten Hang: ";	fflush(stdin);	gets(Tenhang);
    X.nhap(); 
}

void HANG::xuat() {
    cout << "Ma Hang: " << Mahang << endl;
    cout << "Ten Hang: " << Tenhang << endl;
    X.xuat();  
}

int main() {
    HANG a;
    a.nhap();
    cout << "\nThong tin mat hang:\n";
    a.xuat();

    return 0;
}

