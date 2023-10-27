#include <iostream>
#include <string.h>

using namespace std;

class NSX{
	
	private:
		char tenNSX[30];
		char addNSX[30];
	public:
		void nhap();
		void xuat();
		friend class Hang;
};


class Date{
	
	private:
		int d,m,y;
	public:
		void nhap();
		void xuat();
		friend class Tivi;

};

class Hang{
	
	protected:
		char TenHang[30];
		NSX x;
		float dongia;
	public:
		void nhap();
		void xuat();
		Hang();
	
};

class Tivi: public Hang{
	
	private:
		float kt;
		Date ngaynhap;
	public:
		void nhap();
		void xuat();
		Tivi();
		
		
};

void NSX::nhap(){
	
	cout<<"\n Nhap ten nha san xuat:";		fflush(stdin);	gets(tenNSX);
	cout<<"\n Nhap dia chi nha san xuat:";	fflush(stdin);	gets(addNSX);
	
}

void NSX::xuat(){
	
	cout <<"Ten nha san xuat:"<<tenNSX<<endl;
	cout <<"Dia chi nha san xuat:"<<addNSX<<endl;
	
}

void Date::nhap(){
	
	cout<<"\n Nhap ngay:";		cin>>d;
	cout<<"\n Nhap thang:";		cin>>m;
	cout<<"\n Nhap nam:";		cin>>y;
	
}

void Date::xuat(){
	
	cout <<"Ngay thang nam:"<<d<<"/"<<m<<"/"<<y<<endl;
	
}

void Hang::nhap(){
	
	cout <<"Nhap ten hang: ";	fflush(stdin);	gets(TenHang);
	x.nhap();
	cout<<"Nhap don gia: ";		cin>>dongia;
}

void Hang::xuat(){
	
	
	cout<<"Ten hang: "<<TenHang<<endl;
	x.xuat();
	cout<<"Don gia: "<<dongia<<endl;
	
}

void Tivi::nhap(){
	
	Hang::nhap();
	cout<<"Nhap kich thuoc: ";	cin>>kt;
	ngaynhap.nhap();
}

void Tivi::xuat(){
	
	Hang::xuat();
	cout<<"Kich thuoc: "<<kt<<endl;
	ngaynhap.xuat();
	
}

Tivi::Tivi(){
	
	kt=50;
	ngaynhap.d=26;
	ngaynhap.m=9;
	ngaynhap.y=2004;
}

Hang::Hang(){
	
	strcpy(TenHang,"May mat xa");
	strcpy(x.tenNSX,"Sony");
	strcpy(x.addNSX,"Phu Tho");
	dongia=500;	
}



int main(){

	Tivi a;
	a.xuat();
	
	a.nhap();
	cout<<"------------------------TV DA NHAP------------------------"<<endl;
	a.xuat();


	return 0;
}

