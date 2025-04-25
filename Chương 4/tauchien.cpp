#include<iostream>
#include<cstring>
using namespace std;

class TAU{
	private:
		char hang[30];
		float vmax;
		int nam;
	public:
		TAU(const char* hang="", float vmax=0.0,int nam=0){
			strcpy(this->hang,hang);
			this->vmax=vmax;
			this->nam=nam;
		}
//		TAU(){}
		~TAU(){}
		friend istream &operator>>(istream &is, TAU &a){
			cout<<"Nhap ten hang san xuat: "; is.getline(a.hang,30);
			cout<<"Nhap van toc toi da: "; is>>a.vmax;
			cout<<"Nhap nam san xuat: "; is>>a.nam;
			is.ignore();
			return is;
		}
		friend ostream &operator<<(ostream &os, TAU &a){
			os<<"Ten hang san xuat: "<<a.hang<<endl;
			os<<"Van toc toi da: "<<a.vmax<<endl;
			os<<"Nam san xuat: "<<a.vmax<<endl;
			return os;
		}
		int getNam(){
			return nam;
		}
};
class TAUCHIEN:public TAU{
	private:
		char loai[20];
		float tt;
	public:
		TAUCHIEN(const char* loai="", float tt=0.0,const char* hang="", float vmax=0.0,int nam=0):TAU(hang,vmax,nam){
			strcpy(this->loai,loai);
			this->tt=tt;
		}
		//TAUCHIEN(){};
		~TAUCHIEN(){}
		friend istream &operator>>(istream &is, TAUCHIEN &a){
			is>>(TAU&)a;
			cout<<"Nhap loai tau: ";is.getline(a.loai,20);
			cout<<"Nhap trong tai: "; is>>a.tt;
			is.ignore();
			return is;
		}
		friend ostream &operator>>(ostream &os, TAUCHIEN &a){
			os<<(TAU&)a;
			os<<"Loai tau: "<<a.loai<<endl;
			os<<"Trong tai: "<<a.tt<< "tan" <<endl;
			os<<"Tien sua chua: "<<a.tienSua()<< "trieu"<<endl;
			return os;
		}
		int tienSua(){
			if(getNam()<1930) return 50;
			else if(getNam()>1991&&getNam()<2000) return 30;
			else return 10;
		}
		bool operator > (int x){
			return this->tt>x;
		}
		bool operator > (TAUCHIEN &a){
			return this->tt>a.tt;
		}
};
void nhap1(TAU a[], int n){
	for(int i=0; i<n;i++){
		cout<<"Nhap thong tin tau thu "<<i+1<<":\n";
		cin>>a[i];
	}
}
void xuat1(TAU a[], int n){
	for(int i=0; i<n;i++){
		cout<<"Thong tin tau thu "<<i+1<<":\n";
		cout<<a[i];
	}
}
void nhap2(TAUCHIEN a[], int n){
	for(int i=0; i<n;i++){
		cout<<"Nhap thong tin tau chien thu "<<i+1<<":\n";
		cin>>a[i];
	}
}
void xuat2(TAUCHIEN a[], int n){
	for(int i=0; i<n;i++){
		cout<<"Thong tin tau chien thu "<<i+1<<":\n";
		cout<<a[i];
	}
}
void dem(TAUCHIEN a[], int n){
	int cnt=0;
	for(int i=0;i<n;i++){
		if(a[i]>50){
			++cnt;
		}
	}
	cout<<"So luong tau chien co trong tai vuot 50 tan: "<<cnt<<endl;
}
void sx(TAUCHIEN a[], int n){
	for(int i=0; i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]>a[j]){
				TAUCHIEN tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
		}
	}
	cout<<"Danh sach tau chien sau khi sap xep: \n";
	xuat2(a,n);
}
int main(){
	int n,m;
	cout<<"Nhap so luong tau: "; cin>>n;
	cin.ignore();
	TAU *a=new TAU[n];
	nhap1(a,n);
	xuat1(a,n);
	delete[] a;
	cout<<"Nhap so luong tau chien: "; cin>>m;
	cin.ignore();
	TAUCHIEN *b=new TAUCHIEN[m];
	nhap2(b,m);
	xuat2(b,m);
	dem(b,m);
	sx(b,m);
	delete[] b;
}