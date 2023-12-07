#include <iostream>

using namespace std;

class PhanSo{
	private:
		float tu,mau;
	public:
		friend istream &operator>>(istream &in, PhanSo &y);
		friend ostream &operator<<(ostream &out, PhanSo y);
		PhanSo operator +(PhanSo y);
		PhanSo operator -(PhanSo y);
		PhanSo operator *(PhanSo y);
		PhanSo operator /(PhanSo y);
};

istream &operator>>(istream &in, PhanSo &y){
	
	cout<<"Nhap tu so:";
	in >> y.tu;
	cout<<"Nhap mau so:";
	in>>y.mau;
	return in;	
}
ostream &operator<<(ostream &out, PhanSo y){
	
	cout<<y.tu<<"/"<<y.mau<<endl;
	return out;
}

PhanSo PhanSo::operator +(PhanSo y){
	
	PhanSo z;
	z.tu = this->tu * y.mau + y.tu*this->mau;
	z.mau = y.mau * this->mau;
	return z;	
}
PhanSo PhanSo::operator -(PhanSo y){
	
	PhanSo z;
	z.tu = this->tu * y.mau - y.tu*this->mau;
	z.mau = y.mau * this->mau;
	return z;	
}
PhanSo PhanSo::operator *(PhanSo y){
	
	PhanSo z;
	z.tu = this->tu * y.tu;
	z.mau = this->mau * y.mau;
	return z;	
}
PhanSo PhanSo::operator /(PhanSo y){
	
	PhanSo z;
	z.tu = this->tu*y.mau;
	z.mau = this->mau*y.tu;
	return z;	
}

int main(){
	
	PhanSo a,b;
	cin >>a>>b;
	
	cout <<a;
	cout<<b;
	
	PhanSo c = a + b;
    PhanSo d = a - b;
    PhanSo e = a * b;
    PhanSo f = a / b;
	
	cout << "Tong 2 Phan So: " << c;

    cout << "Hieu 2 Phan So: " << d;

    cout << "Nhan 2 Phan So: " << e;

    cout << "Chia 2 Phan So: " << f;
	
	return 0;
}


