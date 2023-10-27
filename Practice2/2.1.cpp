#include <iostream>

using namespace std;

class Date{
	
	private:
		int d,m,y;
	public:
		void nhap();
		void xuat();
};

class NhanSu{
	
	private:
		int MaNS;
		char Hoten[20];
		Date NS;
	public:
		void nhap();
		void xuat();
	
};

void Date::nhap(){
	
	cout<<"Nhap ngay:";		cin>>d;
	cout<<"Nhap thang:";	cin>>m;
	cout<<"Nhap nam:";		cin>>y;
	
}

void Date::xuat(){
	
	cout<<"Ngay thang nam:" <<d<<"/"<<m<<"/"<<y<<endl;
	
}

void NhanSu::nhap(){
	
	cout<<"Nhap ma nhan su:";					cin>>MaNS;
	cout<<"Nhap ho va ten:";	fflush(stdin);	gets(Hoten);
	NS.nhap();
}

void NhanSu::xuat(){
	
	cout<<"Ma nhan su:"<<MaNS<<endl;
	cout<<"Ho ten:"<<Hoten<<endl;
	NS.xuat();
}

int main(){

	NhanSu x;
	x.nhap();
	x.xuat();


	return 0;
}

