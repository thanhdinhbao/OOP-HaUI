#include <iostream>
#include <string.h>
using namespace std;

class Electronic{
	
	public:
		float CongSuat;
		float DienAp;
		Electronic(float a, float b);
		
};

class Maygiat: public Electronic{
	
	public:
		float DungTich;
		char Loai[10];
		Maygiat(float a, float b, float c, char *d);
		void xuat();
		
};

class Tulanh: public Electronic{
	
	public:
		float DungTich;
		int SoNgan;
		Tulanh(float a, float b, float c, int d);
		void xuat();	
};

void Maygiat::xuat(){
	
	cout<<"Cong suat: "<<CongSuat<<endl;
	cout<<"Dien ap: "<<DienAp<<endl;
	cout<<"Dung tich: "<<DungTich<<endl;
	cout<<"Loai: "<<Loai<<endl;
	
}

Electronic::Electronic(float a, float b){
	
	CongSuat =a;
	DienAp =b;
}

Maygiat::Maygiat(float a, float b, float c,char *d) : Electronic(a,b){
	

	DungTich =c;
	strcpy(Loai,d);
		
}

void Tulanh::xuat(){
	
	cout<<"Cong suat: "<<CongSuat<<endl;
	cout<<"Dien ap: "<<DienAp<<endl;
	cout<<"Dung tich: "<<DungTich<<endl;
	cout<<"So ngan: "<<SoNgan<<endl;
	
}

Tulanh::Tulanh(float a,float b,float c,int d) : Electronic(a,b){
	
	DungTich =c;
	SoNgan = d;
		
}

int main(){
	
	Maygiat a(150,220,9,"Cua tren");
	Tulanh b(200,220,100,5);
	
	cout<<"===========THONG TIN MAY GIAT============"<<endl;
	a.xuat();
	cout<<"===========THONG TIN TU LANH============"<<endl;
	b.xuat();
	
	return 0;
	
}




