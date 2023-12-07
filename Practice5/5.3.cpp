#include <bits/stdc++.h>

using namespace std;

class TTB2{
	private:
		float a,b,c;
	public:
		TTB2();
		TTB2(float a, float b, float c);
		friend istream &operator>>(istream &in, TTB2 &y);
		friend ostream &operator<<(ostream &out, TTB2 y);
		TTB2 operator++();
		TTB2 operator+(TTB2 y);
		TTB2 operator-(TTB2 y);
};

TTB2::TTB2(){
	a=0;
	b=0;
	c=0;
}

TTB2::TTB2(float x, float y, float z){
	a=x;
	b=y;
	c=z;
}

istream &operator>>(istream &in, TTB2 &y){
	
	cout<<"Nhap a: ";in>>y.a;
	cout<<"Nhap b: ";in>>y.b;
	cout<<"Nhap c: ";in>>y.c;
	return in;
}

ostream &operator<<(ostream &out, TTB2 y){
	
	out << "Tam thuc bac 2 la:" << y.a<<"x"<<"^2"<<"+"<<y.b<<"x"<<"+"<<y.c<<endl;
	return out;
}

TTB2 TTB2::operator++(){
	
	TTB2 z;
	z.a = -a;
	z.b = -b;
	z.c = -c;
	return z;
	
}

TTB2 TTB2::operator+(TTB2 y){
	
	TTB2 z;
	z.a = a + y.a;
	z.b = b + y.b;;
	z.c = c + y.c;
	return z;
	
}

TTB2 TTB2::operator-(TTB2 y){
	
	TTB2 z;
	z.a = a - y.a;
	z.b = b - y.b;;
	z.c = c - y.c;
	return z;
	
}

int main(){
	
	TTB2 P(2.2,3.3,4.4);
	
	TTB2 Q(4.4,5.5,6.6);
	
	cout<<"Tam thuc P sau khi doi dau la: "<<++P<<endl;
	
	cout<<"Tam thuc Q sau khi doi dau la: "<<++Q<<endl;
	
	cout<<"Tong hai tam thuc la: "<<P+Q<<endl;
	
	cout<<"Hieu hai tam thuc la: "<<P-Q<<endl;
	
	
	
	
	return 0;
}

