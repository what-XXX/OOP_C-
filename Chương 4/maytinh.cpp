#include<iostream>
#include<cstring>
using namespace std;

class HANGHOA{
	private:
		char ma[30],ten[30];
		float donGia;
	public:
		HANGHOA(const char* ma="", const char* ten="", float donGia=0.0){
			strcpy(this->ma,ma);
			strcpy(this->ten,ten);
			this->donGia=donGia;
		}
		~HANGHOA(){}
//		HANGHOA(){}
		friend istream &operator>>(istream &is, HANGHOA &a){
			cout<<"Nhap ma hang: "; is.getline(a.ma,30);
			cout<<"Nhap ten hang san xuat: "; is.getline(a.ten,30);
			cout<<"Nhap don gia: "; is>>a.donGia;
			is.ignore();
			return is;
		}
		friend ostream &operator<<(ostream &os, HANGHOA &a){
			os<<"Ma hang: "<<a.ma<<endl;
			os<<"Ten hang san xuat: "<<a.ten<<endl;
			os<<"Don gia: "<<a.donGia<<endl;
			return os;
		}
		char* getTen(){
			return ten;
		}
};
class MAYTINH:public HANGHOA{
	private:
		int dl, tl;
	public:
		MAYTINH(int dl=0, int tl=0,const char* ma="", const char* ten="", float donGia=0.0):HANGHOA(ma,ten,donGia){
			this->dl=dl;
			this->tl=tl;
		}
//		MAYTINH():HANGHOA(){
//			dl=0;
//			tl=0;
//		}
		~MAYTINH(){}
		friend istream &operator>>(istream &is, MAYTINH &a){
			is>>(HANGHOA&)a;
			cout<<"Nhap dung luong bo nho Ram: "; is>>a.dl;
			cout<<"Nhap trong luong: "; is>>a.tl;
			is.ignore();
			return is;
		}
		friend ostream &operator<<(ostream &os, MAYTINH &a){
			os<<(HANGHOA&)a;
			os<<"Dung luong bo nho Ram: "<<a.dl<<endl;
			os<<"Trong luong: "<<a.tl<<endl;
			os<<"Tien van chuyen: "<<a.tinhTien()<<" kg "<<endl;
			return os;
		}
		int tinhTien(){
			if(tl>2) return 100000;
			else if(tl>1) return 50000;
			else return 30000;
		}
		bool operator ==(int x){
			return this->dl==x;
		}
		bool operator ==(char *x){
			return this->getTen()==x;
		}
};
void nhap1(HANGHOA a[], int n){
	for(int i=0; i<n;i++){
		cout<<"Nhap thong tin hang hoa thu "<<i+1<<":\n";
		cin>>a[i];
	}
}
void xuat1(HANGHOA a[], int n){
	for(int i=0; i<n;i++){
		cout<<"Thong tin hang hoa thu "<<i+1<<":\n";
		cout<<a[i];
	}
}
void nhap2(MAYTINH a[], int n){
	for(int i=0; i<n;i++){
		cout<<"Nhap thong tin may tinh thu "<<i+1<<":\n";
		cin>>a[i];
	}
}
void xuat2(MAYTINH a[], int n){
	for(int i=0; i<n;i++){
		cout<<"Thong tin may tinh thu "<<i+1<<":\n";
		cout<<a[i];
	}
}
void tk1(MAYTINH a[], int n){
	bool check=false;
	cout<<"Danh sach may tinh co dung luong bo nho Ram bang 16:\n";
	for(int i=0; i<n;i++){
		if(a[i]==16){
			cout<<a[i];
			check=true;
			break;
		}
	}
	if(!check) cout<<"Khong co may tinh nao co dung luong bo nho Ram bang 16:\n";
}
void tk2(MAYTINH a[], int n){
	bool check=false;
	cout<<"Thong tin may tinh cua hang Dell:\n";
	for(int i=0; i<n;i++){
		if(a[i]=="Dell"){
			cout<<a[i];
			check=true;
			break;
		}
	}
	if(!check) cout<<"Khong tim thay thong tin may tinh cua hang Dell\n";
}
void them(MAYTINH a[], int &n){
	int k; 
	cout<<"Nhap vi tri k can them k = "; cin>>k;
	cin.ignore();
	for(int i=n; i>=k;i--){
		a[i]=a[i-1];
	}
	cout<<"Nhap danh sach may tinh can them: \n";
	cin>>a[k];
	cout<<"Danh sach may tinh sau khi them: \n";
	n++;
	xuat2(a,n);
}
int main(){
	int n1,n2;
	cout<<"Nhap so luong hang hoa: "; cin>>n1;
	cin.ignore();
	HANGHOA *a=new HANGHOA[n1];
	nhap1(a,n1);
	xuat1(a,n1);
	delete[] a;
	cout<<"Nhap so luong may tinh: ";cin>>n2;
	cin.ignore();
	MAYTINH *b=new MAYTINH[n2+1];
	nhap2(b,n2);
	xuat2(b,n2);
	tk1(b,n2);
	tk2(b,n2);
	them(b,n2);
	delete[] b;
}