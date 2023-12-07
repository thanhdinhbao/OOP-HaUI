#include <bits/stdc++.h>

using namespace std;

class SP{
	private:
		float a,b;
	public:
		SP();
		SP(float a, float b);
		friend istream& operator>>(istream& in, SP &y);
		friend ostream& operator<<(ostream& out, SP y);
		SP operator+(SP y);
		SP operator-(SP y);
};

SP::SP(){
	
	a=0;
	b=0;
	
}

SP::SP(float x, float y){
	
	a=x;
	b=y;	
}

istream& operator>>(istream& in, SP &y){
	
	cout<<"Nhap phan thuc: "; in>>y.a;
	cout<<"Nhap phan ao: "; in>>y.b;
	return in;
	
}

ostream& operator<<(ostream& out, SP y){
	
	out<<y.a<<"+"<<"i*"<<y.b<<endl;
	return out;	
}

SP SP::operator+(SP y){
	
	SP z;
	z.a = a +y.a;
	z.b = b + y.b;
	return z;
	
}

SP SP::operator-(SP y){
	
	SP z;
	z.a = a - y.a;
	z.b = b - y.b;
	return z;
	
}


int main(){
	
	SP a,b,c,d;
	
	cin>>a>>b;
	
	c=a+b;
	d=a-b;
	
	
	
	cout<<"Tong hai so phuc la: "<<c<<endl;
	cout<<"Hieu hai so phuc la: "<<d<<endl;
	
	return 0;
	
}
