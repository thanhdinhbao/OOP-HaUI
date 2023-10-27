#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

class TRUONGDH;

class KHOA{
	
	private:
		char MAKH[10];
		char TENKH[10];
		char TRGKH[30];
	public:
		friend class TRUONGDH;
		friend void SUA(TRUONGDH a);
};

class BAN{
	
	private:
		char MAB[10];
		char TENB[10];
		char NTL[15];
	public:
		friend class TRUONGDH;
};


class TRUONG{
	
	protected:
		char MATRG[10];
		char TENTRG[30];
		char DIACHI [30];
	public:
		void NHAP();
		void XUAT();

};

class TRUONGDH: public TRUONG
{
	private:
		KHOA x[20];
		int n;
		BAN y[20];
		int m;
	public:
		void NHAP();
		void XUAT();
		friend void SUA(TRUONGDH a);
};



void TRUONG::NHAP(){
	
	cout<<"\nNhap ma truong: ";		fflush(stdin);	gets (MATRG);
	cout<<"\nNhap ten truong: ";	fflush(stdin);	gets (TENTRG);
	cout<<"\nNhap dia chi: ";		fflush(stdin);	gets (DIACHI);

}
void TRUONG::XUAT (){
	
	cout<<"\n MA TRUONG: "<<MATRG;
	cout<<"\n TEN TRUONG: "<<TENTRG;
	cout<<"\n DIA CHI: "<<DIACHI;
	
}

void TRUONGDH::NHAP(){
	
	TRUONG::NHAP();
	
	cout<<"\nNhap so khoa:";	cin>>n;
	
	for (int i=0;i<n;i++){
		cout<<"\nNhap ma khoa: ";		fflush(stdin);	gets(x[i].MAKH);
		cout<<"\nNhap ten khoa:";		fflush(stdin);	gets(x[i].TENKH);
		cout<<"\nNhap truong khoa: ";	fflush(stdin);	gets(x[i].TRGKH);

	}	
	
	
	cout<<"\nNhap so ban:";	cin>>m;
	
	for (int i=0;i<m;i++){
		cout<<"\nNhap ma ban	: ";		fflush(stdin);	gets(y[i].MAB);
		cout<<"\nNhap ten ban:";			fflush(stdin);	gets(y[i].TENB);
		cout<<"\nNhap ngay TL ban: ";		fflush(stdin);	gets(y[i].NTL);

	}
	
}

void TRUONGDH::XUAT(){
	
	TRUONG::XUAT();
	
	cout<<"\n\n=== DANH SACH KHOA ==="<<endl;
	cout<<setw(15)<<"MA KHOA"<<setw(15)<<"TEN KHOA"<<setw(15)<<"TRUONG KHOA"<<endl;
	
	for(int i=0;i<n;i++){
		
		cout<<setw(15)<<x[i].MAKH<<setw(15)<<x[i].TENKH<<setw(15)<<x[i].TRGKH<<endl;
	}
	cout<<"\n\n === DANH SACH BAN ==="<<endl;
	cout<<setw(15)<<"MA BAN"<<setw(15)<<"TEN BAN"<<setw(15)<<"NGAY TL"<<endl;
	
	for(int i=0;i<m;i++){
		
		cout<<setw(15)<<y[i].MAB<<setw(15)<<y[i].TENB<<setw(15)<<y[i].NTL<<endl;
	}


}

void SUA(TRUONGDH a){
	
	for (int i=0;i<a.n;i++)
	{
		
		if (strcmp(a.x[i].MAKH, "KH01")==0)
		{
			for (int j=i;j<a.n;j++)
			a.x[j]=a.x[j+1];
			a.n--;
		}
	}
	a.XUAT();	
	
		
	}

int main(){

	TRUONGDH a;
	
	a.NHAP();
	cout<<"\n\n ================  THONG TIN TRUONG DAI HOC VUA NHAP =================" <<endl;
	
	a.XUAT () ;
	
	cout<<"\n\n ================ THONG TIN TRUONG DAI HOC DA SUA ================" <<endl;
	SUA(a);
	



	return 0;
}

