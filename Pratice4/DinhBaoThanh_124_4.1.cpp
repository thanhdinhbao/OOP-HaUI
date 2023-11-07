#include <iostream>

using namespace std;

class Person{
	public:
		char HoTen[20];
		char NgaySinh[20];
		char QueQuan[20];
};

class KySu : public Person{
	
	

	public:
		char Nganh[20];
		int NamTN;
		void nhap();
		void xuat();
			
};

void KySu::nhap(){
	
	cout<<"Nhap ho va ten:";	fflush(stdin);	gets(HoTen);
	cout<<"Nhap ngay sinh:";	fflush(stdin);	gets(NgaySinh);
	cout<<"Nhap que quan:";		fflush(stdin);	gets(QueQuan);
	
	cout<<"Nhap nghanh hoc: ";	fflush(stdin);	gets(Nganh);
	cout<<"Nhap nam TN: ";		cin>>NamTN;
};

void KySu::xuat(){
	
	cout<<"Ho ten: "<<HoTen<<endl;
	cout<<"Ngay sinh: "<<NgaySinh<<endl;
	cout<<"Que quan: "<<QueQuan<<endl;
	
	cout<<"Nganh hoc:"<<Nganh<<endl;
	cout<<"Nam tot nghiep: "<<NamTN<<endl;
	
}

int main(){

	int n;
	cout<<"Nhap vao so luong ky su: ";	cin>>n;
	
	KySu *x = new KySu[n];
	
	for(int i=0;i<n;i++) {
		
		cout<<"Nhap thong tin ky su thu "<<i+1<<endl;
		x[i].nhap();
	}
	
	cout<<"==========THONG TIN KY SU VUA NHAP==========="<<endl;
	
	for(int i=0;i<n;i++) {
	cout<<"Ky su thu"<<i+1<<endl;
	x[i].xuat();
	
	}

	int max = x[0].NamTN;
	int index = 0;
	
	for(int i=1;i<n;i++) {
		
		if(x[i].NamTN > max){
			max = x[i].NamTN;
			index = i;
			
		}
	}
	
	cout<<endl;
	cout<<"=========KY SU CO NAM TOT NGHIEP GAN NHAT==============="<<endl;
	x[index].xuat();
	
	return 0;

}