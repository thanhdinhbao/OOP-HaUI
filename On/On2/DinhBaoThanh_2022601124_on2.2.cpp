#include <iostream>
#include <string.h>

using namespace std;

class Student;

class School{
	
	private:
		char name[20];
		char date[20];
	public:
		friend class Falcuty;
		friend void suatt(Student a);
	
};

class Falcuty{
	
	private:
		char name[20];
		char date[20];
		School x;
	public:
		void nhap();
		void xuat();
		friend void suatt(Student a);

};

class Person{
	
	protected:
		char name[20];
		char birth[20];
		char add[20];
	public:
		void nhap();
		void xuat();
		Person();
		
};

class Student: public Person{
	
	private:
		Falcuty y;
		char Class[20];
		float score;
	public:
		void nhap();
		void xuat();
		Student();	
		friend void suatt(Student a);
	
};

void Falcuty::nhap(){
	
	cout<<"------SCHOOL---------"<<endl;
	cout<<"Nhap ten truong:";		fflush(stdin);	gets(x.name);
	cout<<"Nhap ngay tl truong:";	fflush(stdin);	gets(x.date);
	cout<<"------FALCUTY---------"<<endl;
	cout<<"Nhap ten khoa:";			fflush(stdin);	gets(name);
	cout<<"Nhap ngay tl khoa:";		fflush(stdin);	gets(date);
}

void Falcuty::xuat(){
	
	cout<<"------SCHOOL---------"<<endl;
	cout <<"Ten truong: "<<x.name<<endl;
	cout <<"Ngay tl truong: "<<x.date<<endl;
	cout<<"------FALCUTY---------"<<endl;
	cout <<"Ten khoa: "<<name<<endl;
	cout <<"Ngay tl khoa: "<<date<<endl;
	
}

Person::Person(){
	
	strcpy(name,"Thanh");
	strcpy(birth,"26/09/2004");
	strcpy(add,"Phu Tho");
}

void Person::nhap(){
	
	cout<<"Nhap ten: "; 		fflush(stdin);	gets(name);
	cout<<"Nhap ngay sinh: "; 	fflush(stdin);	gets(birth);
	cout<<"Nhap dia chi: "; 	fflush(stdin);	gets(add);
	
}

void Person::xuat(){

	cout <<"Ho ten: " << name<<endl;
	cout <<"Ngay sinh: " << birth<<endl;
	cout <<"Dia chi: " << add<<endl;

}

Student::Student(){
	
	strcpy(Class,"KHMT01");
	score=10;
}

void Student::nhap(){
	
	y.nhap();
	Person::nhap();
	cout<<"Nhap lop: ";		fflush(stdin);	gets(Class);
	cout<<"Nhap diem: ";					cin>>score;
	
}

void Student::xuat(){
	
	y.xuat();
	Person::xuat();
	cout<<"Lop: "<<Class<<endl;
	cout<<"Diem so: "<<score<<endl;
}

void suatt(Student a){
	
	
	strcpy(a.y.x.name,"DHCNHN");
	a.xuat();
	
	
}


int main(){

	Student a;
	
	cout<<"==============================================================="<<endl;
	
	a.nhap();
	
	cout<<"================THONG TIN HOC SINH VUA NHAP========================"<<endl;
	
	a.xuat();

	cout<<"================THONG TIN HOC SINH SAU KHI SUA========================"<<endl;
	suatt(a);

	return 0;
}

