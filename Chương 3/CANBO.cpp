#include<iostream>
#include<cstring>
using namespace std;

class CANBO{
	private:
		char ma[30], ht[30];
		int soNam;
	public:
		CANBO(const char* ma="", const char* ht="", int soNam=0){
			strcpy(this->ma,ma);
			strcpy(this->ht,ht);
			this->soNam=soNam;
		}
		~CANBO(){}
		friend istream &operator>>(istream &is, CANBO &a){
			cout<<"Nhap ma can bo: "; is.getline(a.ma,30);
			cout<<"Nhap ho ten: "; is.getline(a.ht,30);
			cout<<"Nhap so nam cong tac: "; is>>a.soNam;
			is.ignore();
			return is;
		}
		int tinhLuong(){
			if(soNam>=20) return 15;
			else if(soNam>=10) return 10;
			else return 7;
		}
		friend ostream &operator<<(ostream &os, CANBO &a){
			os<<"Ma can bo: "<<a.ma<<endl;
			os<<"Ho ten: "<<a.ht<<endl;
			os<<"So nam cong tac: "<<a.soNam<<endl;
			os<<"Luong hang thang: "<<a.tinhLuong()<<" trieu dong"<<endl;
			return os;
		}
		bool operator == (char *x){
			return this->ma==x;
		}
		char* getX(){
			return ma;
		}
		int getY(){
			return soNam;
		}
		bool operator < (CANBO &x){
			return this->soNam<x.soNam;
		}
};
void nhap(CANBO a[], int n){
	for(int i=0; i<n;i++){
		cout<<"Nhap thong tin can bo thu "<<i+1<<":\n";
		cin>>a[i];
	}
}
void xuat(CANBO a[], int n){
	for(int i=0; i<n;i++){
		cout<<"Thong tin can bo thu "<<i+1<<":\n";
		cout<<a[i];
	}
}
void tk(CANBO a[], int n){
	char x[30];
	cout<<"Nhap ma can bo can tim: "; cin>>x;
	cin.ignore();
	bool check=false;
	for(int i=0; i<n;i++){
		if(a[i].getX()==x){
			cout<<"Thong tin cua can bo co ma la: "<<x<<"\n";
			cout<<a[i];
			check=true;
			break;
		}
	}
	if(!check) cout<<"Khong co can bo nao co ma la: "<<x<<endl;
}
void sx(CANBO a[], int n){
	for(int i=0; i<n-1;i++){
		for(int j=i+1; j<n;j++){
			if(a[i].getY()<a[j].getY()){
				CANBO tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
		}
	}
	cout<<"Danh sach can bo sau khi sap xep theo thu tu giam dan: \n";
	xuat(a,n);
}
int main()
{
	int n;
	do{
		cout<<"Nhap so luong danh sach can bo: "; cin>>n;
		cin.ignore();
	}while(n<=0);
	CANBO *a=new CANBO[n];
	nhap(a,n);
	xuat(a,n);
	tk(a,n);
	sx(a,n);
	delete[] a;
}