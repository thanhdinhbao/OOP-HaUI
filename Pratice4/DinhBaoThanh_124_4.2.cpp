#include <iostream>

using namespace std;

class Printer{
	
	public:
		float TrongLuong;
		char HangSX[20];
		int NamSX;
		float speed;
		friend void Sua(Printer &a);
};

class DotPrinter : public Printer{
	
	public:
		float MDKim;
		void nhap();
		void xuat();
};

class LaserPrinter: public Printer{
	
	public:
		float DPI;
		void nhap();
		void xuat();			
};

void DotPrinter::nhap(){
	
	cout<<"Nhap trong luong: ";						cin>>TrongLuong;
	cout<<"Nhap hang san xuat:";	fflush(stdin);	gets(HangSX);
	cout<<"Nhap nam san xuat: ";					cin>>NamSX;
	cout<<"Nhap toc do: ";							cin>>speed;
	
	cout<<"Nhap mat do kim: ";						cin>>MDKim;
}

void DotPrinter::xuat(){
	
	cout<<"Trong luong: "<<TrongLuong<<endl;
	cout<<"Hang san xuat:"<<HangSX<<endl;
	cout<<"Nam san xuat: "<<NamSX<<endl;
	cout<<"Toc do: "<<speed<<endl;
	
	cout<<"Mat do kim: "<<MDKim<<endl;
	
}

void LaserPrinter::nhap(){
	
	cout<<"Nhap trong luong: ";						cin>>TrongLuong;
	cout<<"Nhap hang san xuat:";	fflush(stdin);	gets(HangSX);
	cout<<"Nhap nam san xuat: ";					cin>>NamSX;
	cout<<"Nhap toc do: ";							cin>>speed;
	
	cout<<"Nhap do phan giai: ";					cin>>DPI;
}

void LaserPrinter::xuat(){
	
	cout<<"Trong luong: "<<TrongLuong<<endl;
	cout<<"Hang san xuat:"<<HangSX<<endl;
	cout<<"Nam san xuat: "<<NamSX<<endl;
	cout<<"Toc do: "<<speed<<endl;
	
	cout<<"Do phan giai: "<<DPI<<endl;
	
}

void Sua(Printer &a){
	
	a.NamSX = 2022;
}

int main(){
	
	DotPrinter dp;
	LaserPrinter lp;
	
	cout<<"Nhap thong tin dot printer"<<endl;
	dp.nhap();
	cout<<"Nhap thong tin lazer printer"<<endl;
	lp.nhap();
	cout<<endl;
	cout<<"===========DOT PRINTER========="<<endl;
	
	dp.xuat();

	cout<<"===========LASER PRINTER========="<<endl;
	
	lp.xuat();
	
	Sua(dp);
	Sua(lp);
	
	cout<<"===========DOT PRINTER SAU KHI SUA========="<<endl;
	dp.xuat();
	cout<<"===========LASER PRINTER SAU KHI SUA========="<<endl;
	lp.xuat();
	
	
	return 0;
}

