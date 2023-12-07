#include <iostream>

using namespace std;

class Oto;
class Vehicle{
	
	public:
		char brand[20];
		int year;
		char Hang[20];
		void nhap();
		void xuat();
		friend void Sua(Oto &a);
};

class Oto : public Vehicle{
	
	public:
		int SoCho;
		float DungTich;
		void nhap();
		void xuat();
};

class Moto : public Vehicle{
	
	public:
		int PhanKhoi;
		void nhap();
		void xuat();
};

void Vehicle::nhap(){
	
	cout<<"Nhap nhan hieu: ";	fflush(stdin); gets(brand);
	cout<<"Nhap nam san xuat: ";	cin>>year;
}

void Vehicle::xuat(){
	
	cout <<"Nhan hieu: "<<brand<<endl;
	cout<<"Nam san xuat: "<<year<<endl;

}

void Oto::nhap(){
	
	Vehicle::nhap();
	
	cout<<"Nhap so cho ngoi: ";	cin>>SoCho;
	cout<<"Nhap dung tich: ";	cin>>DungTich;
}

void Oto::xuat(){
	
	Vehicle::xuat();
	cout<<"So cho ngoi: "<<SoCho<<endl;
	cout<<"Dung tich: "<<DungTich<<endl;
	
}

void Moto::nhap(){
	
	Vehicle::nhap();
	
	cout<<"Nhap phan khoi: ";	cin>>PhanKhoi;

}

void Moto::xuat(){
	
	Vehicle::xuat();
	
	cout<<"Nhap phan khoi: "<<PhanKhoi<<endl;

}

void Sua(Oto &a){
	
	a.DungTich = 3.0;
}

int main(){
	
	Oto o1;
	Moto m1;
	
	cout<<"Nhap thong tin o to :"<<endl;
	o1.nhap();
	
	cout<<"Nhap thong tin mo to :"<<endl;
	m1.nhap();
	
	cout<<"==========THONG TIN O TO=========="<<endl;
	o1.xuat();
	
	cout<<"==========THONG TIN MO TO=========="<<endl;
	m1.xuat();
	
	Sua(o1);
	
	cout<<"==========THONG TIN O TO SAU KHI SUA=========="<<endl;
	o1.xuat();
	
	
}


