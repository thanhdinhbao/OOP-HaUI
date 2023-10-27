#include <iostream>

using namespace std;

class Quanly{
	
	private:
		int maql;
		char Hoten[30];
	public:
		void nhap();
		void xuat();
		
};

class May{
	
	private:
		int mamay;
		char km[20];
		char tt[20];
};

class Phongmay{
	
	private:
		int maphong;
		char tenphong[20];
		float dt;
		int n;
		Quanly x;
		May *y;
	public:
		void nhap();
		void xuat();
};

void Quanly::nhap(){
	
	cout<<"Nhap ma quan ly:";					cin>>maql;
	cout<<"Nhap ho va ten:";	fflush(stdin);	gets(ten);
}

void Quanly::xuat(){
	
	cout<<"Ma quan ly: " <<maql<<endl;
	cout<<"Ho va ten: "<<ten<<endl;
}

void May::nhap(){
	
	cout<<"Nhap ma may: ";							cin>>mamay;
	cout<<"Nhap kieu may:";		fflush(stdin);		gets(km);
	cout<<"Nhap tinh trang:";	fflush(stdin);		gets(tt);
}

void May::xuat(){
	
	cout<<"Ma may: "<<mamay<<endl;
	cout<<"Kieu may: "<<km<<endl;
	cout<<"Tinh trang: "<<tt<<endl;
}

void Phongmay::nhap(){
	
	cout<<"Nhap ma phong: ";							cin>>maphong;
	cout<<"Nhap ten phong:";		fflush(stdin);		gets(tenphong);
	cout<<"Nhap dien tich:";							cin>>dt;
	
	Quanly x;
	May *y;
}



int main(){

	


	return 0;
}

