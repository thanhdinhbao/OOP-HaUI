#include <iostream>

using namespace std;

class Hang{
	
	private:
		int ma;
		char ten[30];
		float dg;
	public:
		void nhap();
		void xuat();
};

class Phieu{
	
	private:
		int mp;
		Hang x[50];
		int n;
	public:
		void nhap();
		void xuat();
};

void Hang::nhap(){
	
	cout<<"Nhap ma hang:";	cin>>ma;
	cout<<"Nhap ten hang:";	fflush(stdin);	gets(ten);
	cout<<"Nhap don gia:";	cin>>dg;
	
}

void Hang::xuat(){
	
	cout<<"Ma hang: "<<ma<<endl;
	cout<<"Ten hang: "<<ten<<endl;
	cout<<"Don gia: "<<dg<<endl;
}

void Phieu::nhap(){
	
	cout<<"Nhap ma phieu:";	cin>>mp;
	cout<<"Nhap vao so luong hang:";	cin>>n;
	
	for (int i = 0; i < n; i++) {
        cout << "Nhap Thong Tin Mat Hang Thu " << i + 1 << endl;
        x[i].nhap(); 
    }
}

void Phieu::xuat(){
	
	cout<<"Ma phieu: "<<mp<<endl;
	cout << "Danh Sach Mat Hang trong Phieu:" << endl;
		for (int i = 0; i < n; i++) {
            x[i].xuat(); 
        }		
}

int main(){
	
	Phieu p1;

	p1.nhap();
	
	cout<<"========Thong tin mat hang==========="<<endl;
	
	p1.xuat();

	return 0;
}

