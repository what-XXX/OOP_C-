#include<iostream>
#include<cstring>
using namespace std;

const int maxn=10000;
class DOCGIA{
	private:
		char ma[30], ten[30];
	public:
		virtual void nhap(){
			cout<<"Nhap ma doc gia: "; cin.getline(ma,30);
			cout<<"Nhap ten doc gia: "; cin.getline(ten,30);
			cin.ignore();
		}
		virtual void xuat(){
			cout<<"Ma doc gia: "<<ma<<endl;
			cout<<"Ten doc gia: "<<ten<<endl;
		}
		virtual float tinhPhi()=0;
};
class DOCGIATHUONG:public DOCGIA{
	private:
		int month;
	public:
		void nhap(){
			DOCGIA::nhap();
			cout<<"Nhap so thang dang ky: "; cin>>month;
			cin.ignore();
		}
		void xuat(){
			DOCGIA::xuat();
			cout<<"So thang da dang ky: "<<month<<endl;
		}
		virtual float tinhPhi(){
			return month*10000;
		}
		
};
class DOCGIAVIP:public DOCGIA{
	private:
		int month;
		float heso;
	public:
		virtual void nhap(){
			DOCGIA::nhap();
			cout<<"Nhap so thang dang ky: "; cin>>month;
			cout<<"Nhap he so: "; cin>>heso;
			cin.ignore();
		}
		virtual void xuat(){
			DOCGIA::xuat();
			cout<<"So thang dang ky: "<<month<<endl;
			cout<<"He so: "<<heso<<endl;
		}
		virtual float tinhPhi(){
			return month*20000*heso;
		}
};
void nhapDS(DOCGIA* a[], int &n){
	int lc;
	while(1){
		cout<<"Chon loai doc gia (1-Thuong,2-Vip, 0-Ket thuc): ";
		if(lc==0) break;
		cin.ignore();
		if(n>=maxn){
			cout<<"Danh sach nay da day!"<<endl;
			break;
		}
		if(lc==1){
			a[n]=new DOCGIATHUONG();
		}
		else if(lc==2){
			a[n]=new DOCGIAVIP();
		}
		else{
			cout<<"Lua chon khong hop le!"<<endl;
		}
		a[n]->nhap();
		n++;
	}
}
void xuatDS(DOCGIA* a[], int n){
	for(int i=0; i<n;i++){
		cout<<"Thong tin doc gia thu "<<i+1<<":\n";
		a[i]->xuat();
	}
}
DOCGIA* tk(DOCGIA* a[], int n){
	DOCGIA* res=a[0];
	float maxPhi=res->tinhPhi();
	for(int i=1; i<n;i++){
		float curPhi=a[i]->tinhPhi();
		if(curPhi>maxPhi){
			maxPhi=curPhi;
			res=a[i];
		}
	}
	return res;
}
void menu(){
	cout<<"\n----MENU----"<<endl;
	cout<<"1. Nhap danh sach doc gia"<<endl;
	cout<<"2. Xuat danh sach doc gia"<<endl;
	cout<<"3. Tim doc gia co phi dang ky cao nhat"<<endl;
	cout<<"0. Thoat chuong trinh"<<endl;
}
int main(){
	DOCGIA* a[maxn];
	int n=0;
	int lc;
	do{
		cout<<"Nhap lua chon cua ban: "; 
		menu();
		cin>>lc;
		cin.ignore();
		switch(lc){
			case 1:
				nhapDS(a,n);
				break;
			case 2:
				xuatDS(a,n);
				break;
			case 3:{
				DOCGIA* maxDG=tk(a,n);
				if(maxDG){
					cout<<"\n Doc gia co phi dang ky cao nhat:\n";
					maxDG->xuat();
				}
				else{
					cout<<"Khong co doc gia co phi dang ky cao nhat\n";
				}
				break;
		}
			case 0:
				cout<<"Ket thuc chuong trinh\n";
				break;
			default:
				cout<<"Lua cho n cua ban khong hop le! Vui long nhap lai"<<endl;
		}
	}while(lc!=0);
}