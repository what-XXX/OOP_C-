#include<iostream>
#include<cstring>
using namespace std;
const int maxn=10000;

class BACSI{
	private:
		char ma[30],ht[30],cm[30];
	public:
		virtual void nhap(){
			cout<<"Nhap ma bac si: "; cin.getline(ma,30);
			cout<<"Nhap ho ten: "; cin.getline(ht,30);
			cout<<"Nhap trinh do chuyen mon: "; cin.getline(cm,30);
		}
		virtual void xuat(){
			cout<<"Ma bac si: "<<ma<<endl;
			cout<<"Ho ten: "<<ht<<endl;
			cout<<"Trinh do chuyen mon: "<<cm<<endl;
		}
		virtual float thuNhap()=0;
		char* getX(){
			return cm;
		}
};
class BACSINHI:public BACSI{
	private:
		int soNgayTruc;
	public:
		void nhap(){
			BACSI::nhap();
			cout<<"Nhap so ngay truc: "; cin>>soNgayTruc;
			cin.ignore();
		}
		void xuat(){
			BACSI::xuat();
			cout<<"So ngay truc: "<<soNgayTruc<<endl;
			cout<<"Thu nhap: "<<thuNhap()<<endl;
		}
		virtual float thuNhap(){
			int pc=0;
			if(strcmp(getX(),"Giao su")==0){
				pc=1000000;
			}
			else if(strcmp(getX(),"Pho giao su")==0){
				pc=800000;
			}
			else if(strcmp(getX(),"Tien si")==0){
				pc=500000;
			}
			else if(strcmp(getX(),"Thac si")==0){
				pc=300000;
			}
			else{
				pc=0;
			}
			return soNgayTruc*800000+pc;
		}
};
class BACSITIM:public BACSI{
	private:
		int soca;
	public:
		void nhap(){
			BACSI::nhap();
			cout<<"Nhap so ca cap cuu: "; cin>>soca;
			cin.ignore();
		}
		void xuat(){
			BACSI::xuat();
			cout<<"So ca cap cuu: "<<soca<<endl;
			cout<<"Thu nhap: "<<thuNhap()<<endl;
		}
		virtual float thuNhap(){
			int pc=0;
			if(strcmp(getX(),"Giao su")==0){
				pc=2000000;
			}
			else if(strcmp(getX(),"Pho giao su")==0){
				pc=1000000;
			}
			else if(strcmp(getX(),"Tien si")==0){
				pc=800000;
			}
			else if(strcmp(getX(),"Thac si")==0){
				pc=500000;
			}
			else{
				pc=0;
			}
			return soca*1500000+pc;
		}
};
void nhapDS(BACSI* a[], int &n){
	int lc;
	while(1){
		cout<<"Lua chon doi tuong: (1- Bac si nhi, 2- Bac si tim, 3- Thoat chuong trinh)\n";
		cin>>lc;
		cin.ignore();
		if(lc==3) break;
		if(lc==1){
			a[n]=new BACSINHI();
		}
		else if(lc==2){
			a[n]=new BACSITIM();
		}
		else{
			cout<<"Lua chon khong phu hop\n";
		}
		a[n]->nhap();
		n++;
	}
}
void xuatDS(BACSI* a[], int n){
	for(int i=0; i<n;i++){
		cout<<"Thong tin bac si thu "<<i+1<<":\n";
		a[i]->xuat();
	}
}
float tinh(BACSI* a[], int n){
	float res=0;
	for(int i=0; i<n;i++){
		res+=a[i]->thuNhap();
	}
	return res/n;
}
void menu(){
	cout<<"----Menu----\n";
	cout<<"1. Nhap danh sach bac si"<<endl;
	cout<<"2. Xuat danh sach bac si"<<endl;
	cout<<"3. Tinh trung binh luong"<<endl;
	cout<<"4. Thoat chuong trinh"<<endl;
	cout<<"Nhap lua chon cua ban: "<<endl;
}
int main(){
	BACSI* a[maxn];
	int lc;
	int n=0;
	do{
		menu();
		cin>>lc;
		cin.ignore();
		switch (lc){
			case 1:
				nhapDS(a,n);
				break;
			case 2:
				xuatDS(a,n);
				break;
			case 3:
				cout<<tinh(a,n)<<endl;
				break;
			case 4:
				cout<<"Ban da thoat chuong trinh\n";
				break;
			default:
				cout<<"Lua chon khong hop le! Vui long nhap lai"<<endl;
				
		}	
	}while(lc!=0);
}