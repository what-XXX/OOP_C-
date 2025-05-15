#include<iostream>
#include<cstring>
using namespace std;

class HOCVIEN{
	private:
		char ma[30],ht[30];
		int soGio;
	public:
		HOCVIEN(const char* ma="", const char* ht="", int soGio=0){
			strcpy(this->ma,ma);
			strcpy(this->ht,ht);
			this->soGio=soGio;
		}
		~HOCVIEN(){}
		friend istream &operator>>(istream &is, HOCVIEN &a){
			cout<<"Nhap ma hoc vien: "; cin.getline(a.ma,30);
			cout<<"Nhap ho ten: "; cin.getline(a.ht,30);
			cout<<"Nhap so gio: "; cin>>a.soGio;
			cin.ignore();
			return is;
		}
		int tinh(){
			if(soGio>=200) return 30;
			else if(soGio>=100&&soGio<200) return 20;
			else return 10;
		}
		friend ostream &operator<<(ostream &os, HOCVIEN &a){
			os<<"Ma hoc vien: "<<a.ma<<endl;
			os<<"Ho ten: "<<a.ht<<endl;
			os<<"So gio: "<<a.soGio<<endl;
			os<<"Hoc phi: "<<a.tinh()<<" trieu dong"<<endl;
			return os;
		}
		bool operator >(HOCVIEN &x){
			return this->soGio>x.soGio;
		}
		bool operator <(HOCVIEN &x){
			return this->soGio>x.soGio;
		}
		int getX(){
			return soGio;
		}
};
void nhap(HOCVIEN a[], int n){
	for(int i=0; i<n;i++){
		cout<<"Nhap thong tin hoc vien thu "<<i+1<<":\n";
		cin>>a[i];
	}
}
void xuat(HOCVIEN a[], int n){
	for(int i=0; i<n;i++){
		cout<<"Thong tin hoc vien thu "<<i+1<<":\n";
		cout<<a[i];
	}
}
void tk(HOCVIEN a[], int n){
	bool check=false;
	int x;
	do{
		cout<<"\nNhap so gio tich luy: \n"; cin>>x;
		cin.ignore(); 
	}while(x<=0);
	for(int i=0; i<n;i++){
		if(a[i].getX()>x){
			cout<<"Thong tin hoc vien co so gio hoc tich luy lon hon "<<x<<":\n";
			cout<<a[i];
			check=true;
			break;
		}
	}
	if(!check){
		cout<<"Khong co hoc vien co so gio hoc tich luy lon hon "<<x<<":\n";
	}	
}
void sx(HOCVIEN a[], int n){
	for(int i=0; i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i].getX()<a[j].getX()){
				HOCVIEN tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;	
			}
		}
	}
	cout<<"\n Danh sach hoc vien sau khi sap xep theo thu tu giam dan: \n";
	xuat(a,n);
}
int main()
{
	int n;
	do{
		cout<<"Nhap so luong hoc vien: \n"; cin>>n;
		cin.ignore();
	}while(n<=0);
	HOCVIEN *a= new HOCVIEN[n];
	nhap(a,n);
	xuat(a,n);
	tk(a,n);
	sx(a,n);
	delete[] a;
}