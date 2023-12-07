#include <bits/stdc++.h>

using namespace std;

class Hang{
	public:
		char MaHang[20];
		char TenHang[20];
		float DonGia;
		int SoLuong;
		int Nam;

		Hang();
		Hang(char MaHang, char TenHang, float DonGia, int SoLuong, int Nam);
		friend istream& operator>>(istream& in, Hang &y);
		friend ostream& operator<<(ostream& out, Hang y);
};

Hang::Hang(){
	
	strcpy(MaHang, "H01");
	strcpy(TenHang, "TV");
	DonGia = 100;
	SoLuong = 50;
	Nam = 2020;
	
}

istream& operator>>(istream& in, Hang &y){
	
	cout<<"Nhap ma hang: "<<endl; 	fflush(stdin);	gets(y.MaHang);
	cout<<"Nhap ten hang: "<<endl; 	fflush(stdin);	gets(y.TenHang);
	cout<<"Nhap don gia: "<<endl; 					in>>y.DonGia;
	cout<<"Nhap so luong : "<<endl; 				in>>y.SoLuong;
	cout<<"Nhap nam: "<<endl; 						in>>y.Nam;
	
	return in;
}

ostream& operator<<(ostream& out, Hang y){
	
	out<<"Ma hang: "<<y.MaHang<<endl;
	out<<"Ten hang: "<<y.TenHang<<endl;
	out<<"Don gia: "<<y.DonGia<<endl;
	out<<"So luong : "<<y.SoLuong<<endl;
	out<<"Nam: "<<y.Nam<<endl;
	
	return out;
}

int main(){
	
	Hang a[50];
	int n;
	cout<<"Nhap so luong mat hang: ";	cin>>n;
	
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	

	
	bool flag = false;
	for(int i=0; i<n;i++){
		if (strcmp(a[i].TenHang,"Iphone 12") == 0){
			flag = true;
		}
	}
	
	
	for (int i=0;i<n;i++){
		cout<<a[i];
	}
	
	cout<<endl; 
	
	if(flag){
		cout<<"Co iphone 12"<<endl;
	}
	else{
		cout<<"Khong co iphone 12"<<endl;
	}
	
	
	for(int i=0;i<n-1;i++){
		for(int j=n+1;j<n;j++){
			if(a[i].DonGia < a[j].DonGia){
				Hang tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
	
    // Xóa m?t hàng có mã H005
    for (int i = 0; i < n; ++i) {
        if (strcmp(a[i].MaHang, "H005") == 0) {
            for (int j = i; j < n - 1; ++j) {
                a[j] = a[j + 1];
            }
            --n;  
            break;
        }
    }
    
    // Xóa m?i m?t hàng có don giá nh? hon 20
    for (int i = 0; i < n; ++i) {
        if (a[i].DonGia < 20) {
            for (int j = i; j < n - 1; ++j) {
                a[j] = a[j + 1];
            }
            --n;  
            --i;  
        }
    }
	
	
	return 0;
}
