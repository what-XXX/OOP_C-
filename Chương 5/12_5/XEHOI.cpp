#include<iostream>
#include<cstring>
using namespace std;

const int maxn=10002;
class XEHOI{
	private:
		char ma[30],hang[30];
		float gia1;
	public:
		virtual void nhap(){
			cout<<"Nhap ma xe: "; cin.getline(ma,30);
			cout<<"Nhap hang xe: "; cin.getline(hang,30);
			cout<<"Nhap gia truoc thue: "; cin>>gia1;
		}
		virtual void xuat(){
			cout<<"Ma xe: "<<ma<<endl;
			cout<<"Hang xe: "<<hang<<endl;
			cout<<"Gia truoc thue: "<<gia1<<endl;
		}
		virtual float gia2()=0;
		float getX(){
			return gia1;
		}
};
class XEXANG:public XEHOI{
	private:
		float mucTieuThuTB;
	public:
		void nhap(){
			XEHOI::nhap();
			cout<<"Nhap muc tieu thu trung binh: "; cin>>mucTieuThuTB;
			cin.ignore();
		}	
		void xuat(){
			XEHOI::xuat();
			cout<<"Muc tieu thu trung binh: "<<mucTieuThuTB<<endl;
			cout<<"Gia sau thue: "<<gia2()<<endl;
		}
		virtual float gia2(){
			return getX()+getX()*0.12;
		}
};
class XEDIEN:public XEHOI{
	private:
		int dl;
	public:
		void nhap(){
			XEHOI::nhap();
			cout<<"Nhap dung luong pin: "; cin>>dl;
			cin.ignore();
		}
		void xuat(){
			XEHOI::xuat();
			cout<<"Dung luong pin: "<<dl<<endl;
			cout<<"Gia sau thue: "<<gia2()<<endl;
		}
		virtual float gia2(){
			return getX()+getX()*0.08;
		}
};
void nhapDS(XEHOI* a[], int &n){
	int lc;
	while(1){
		cout<<"Lua chon doi tuong xe hoi: (0-Thoat chuong trinh,1-xe xang,2-xe dien)\n";
		cin>>lc;
		cin.ignore();
		if(lc==0) break;
		if(n>maxn){
			cout<<"Danh sach da day\n";
		}
		if(lc==1){
			a[n]=new XEXANG();
		}
		else if(lc==2){
			a[n]= new XEDIEN();
		}
		else{
			cout<<"Lua chon cua ban khong phu hop\n";
			break;
		}
		a[n]->nhap();
		n++;
	}
}
void xuatDS(XEHOI* a[], int n){
	for(int i=0; i<n;i++){
		cout<<"Thong tin xe thu "<<i+1<<":\n";
		a[i]->xuat();
	}
}
float tinh(XEHOI* a[], int n){
	float res=0;
	for(int i=0; i<n;i++){
		res+=a[i]->gia2();
	}
	return res/n;
}
void menu(){
	cout<<"----MENU----\n";
	cout<<"1. Nhap danh sach xe hoi"<<endl;
	cout<<"2. Xuat danh sach xe hoi"<<endl;
	cout<<"3. Tinh trung binh gia thue"<<endl;
	cout<<"0. Thoat chuong trinh"<<endl;
	cout<<"-------------\n";
	cout<<"Nhap lua chon cua ban: "<<endl;
}
int main()
{
	XEHOI* a[maxn];
	int n=0, lc;
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
				cout<<"Trung binh gia sau thue cua cac xe hoi: "<<tinh(a,n)<<endl;
				break;
			case 0:
				cout<<"Ban da thoat chuong trinh\n";
				break;
			default:
				cout<<"Lua chon cua ban khong hop le. Vui long nhap lai\n";
		}
	}while(lc!=0);
	
}