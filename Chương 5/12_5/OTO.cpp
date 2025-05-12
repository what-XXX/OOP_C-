#include<iostream>
#include<cstring>
using namespace std;

const int maxn=10001;
class OTO{
	private:
		char ma[30], ten[30];
		float gia1;//gia truoc thue
	public:
		virtual void nhap(){
			cout<<"Nhap ma oto: "; cin.getline(ma,30);
			cout<<"Nhap ten oto: "; cin.getline(ten,30);
			cout<<"Nhap gia truoc thue: "; cin>>gia1;
		}
		virtual void xuat(){
			cout<<"Ma oto: "<<ma<<endl;
			cout<<"Ten oto: "<<ten<<endl;
			cout<<"Gia truoc thue: "<<gia1<<endl;
		}
		virtual float gia2()=0;//gia sau thue
		float getX(){
			return gia1;
		}
};
class OTOTAI: public OTO{
	private:
		float tt;
	public:
		void nhap(){
			OTO::nhap();
			cout<<"Nhap trong tai: "; cin>>tt;
			cin.ignore();
		}
		void xuat(){
			OTO::xuat();
			cout<<"Trong tai: "<<tt<<endl;
			cout<<"Gia sau thue: "<<gia2()<<endl;
		}
		virtual float gia2(){
			return getX()+getX()*0.2;
		}
};
class OTOKHACH: public OTO{
	private:
		int choNgoi;
	public:
		void nhap(){
			OTO::nhap();
			cout<<"Nhap so luong cho ngoi: "; cin>>choNgoi;
			cin.ignore();
		}
		void xuat(){
			OTO::xuat();
			cout<<"So luong cho ngoi: "<<choNgoi<<endl;
			cout<<"Gia sau thue: "<<gia2()<<endl;
		}
		virtual float gia2(){
			return getX()+getX()*0.4;
		}
};
void nhapDS(OTO* a[], int &n){
	int lc;
	while(1){
		cout<<"Nhap doi luong xe oto: (0-Thoat chuong trinh, 1- Xe tai, 2-Xe khach)\n";
		cin>>lc;
		if(lc==0) break;
		cin.ignore();
		if(n>=maxn){
			cout<<"Danh sach da day\n";
			break;
		}
		if(lc==1){
			a[n]=new OTOTAI();
		}
		else if(lc==2){
			a[n]=new OTOKHACH();
		}
		else{
			cout<<"Khong co doi tuong nao phu hop voi lua chon cua ban!\n";
		}
		a[n]->nhap();
		n++;
	}
}
void xuatDS(OTO* a[], int n){
	for(int i=0; i<n;i++){
		cout<<"Thong tin oto thu "<<i+1<<":\n";
		a[i]->xuat();
	}
}
float tongThue(OTO* a[], int n){
	float sum=0;
	for(int i=0; i<n;i++){
		sum+=a[i]->gia2();
	}
}
void menu(){
	cout<<"----MENU----\n";
	cout<<"1. Nhap thong tin oto"<<endl;
	cout<<"2. Xuat danh sach oto"<<endl;
	cout<<"3. Tinh tong gia sau thue"<<endl;
	cout<<"0. Thoat chuong trinh"<<endl;
	cout<<"-------------\n";
	cout<<"Nhap lua chon cua ban: \n";
}
int main()
{
	OTO* a[maxn];
	int lc, n=0;
	do{
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
			case 3: 
				cout<<"Tong gia thue cua cac oto da nhap: "<<tongThue(a,n)<<endl;
				break;
			case 0:
				cout<<"Ban da thoat chuong trinh"<<endl;
				break;
			default:
				cout<<"Lua chon khong hop le! Vui long nhap lai";
		}
	}while(lc!=0);
}