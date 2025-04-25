#include<iostream>
#include<cstring>
using namespace std;

class SQ{
	private:
		char ma[30],ht[30],cb[20],dvct[30];
		float luong;
	public:
		SQ(const char* ma="", const char* ht="", const char* cb="",const char* dvct="", float luong=0.0){
			strcpy(this->ma,ma);
			strcpy(this->ht,ht);
			strcpy(this->cb,cb);
			strcpy(this->dvct,dvct);
			this->luong=luong;
		}
		~SQ(){}
		friend istream &operator >>(istream &is, SQ &a){
			cout<<"Nhap ma: "; is.getline(a.ma,30);
			cout<<"Nhap ho ten: "; is.getline(a.ht,30);
			cout<<"Nhap cap bac: "; is.getline(a.cb,20);
			cout<<"Nhap don vi cong tac: ";is.getline(a.dvct,30);
			cout<<"Nhap luong: ";is>>a.luong;
			is.ignore();
			return is;
		}
		float tinhThue() const {
			return luong-luong*0.1;
		}
		friend ostream &operator <<(ostream &os, SQ &a){
			os<<"Ma: "<<a.ma<<endl;
			os<<"Ho ten: "<<a.ht<<endl;
			os<<"Cap bac: "<<a.cb<<endl;
			os<<"Don vi cong tac: "<<a.dvct<<endl;
			os<<"Luong: "<<a.luong<<endl;
			os<<"Luong sau thue: "<<a.tinhThue()<<endl;
		}
		bool operator ==(char *x){
			return strcmp(this->ht,x)==0;
		}
		bool operator <(SQ &a){
			return this->luong<a.luong;
		}
};
void nhap(SQ a[], int n){
	for(int i=0; i<n;i++){
		cout<<"Nhap thong tin si quan thu "<<i+1<<":\n";
		cin>>a[i];
	}
}
void xuat(SQ a[], int n){
	for(int i=0; i<n;i++){
		cout<<"Thong tin si quan thu "<<i+1<<":\n";
		cout<<a[i];
	}
}
void tk(SQ a[], int n){
	bool check=false;
	for(int i=0; i<n;i++){
		if(a[i]=="Minh"){
			cout<<"Thong tin cac si quan ten Minh la:\n";
			cout<<a[i];
		}
	}
}
void sx(SQ a[], int n){
	for(int i=0; i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]<a[j]){
				SQ tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
		}
	}
	cout<<"Danh sach sau khi sap xep: \n";
	xuat(a,n);
}
int main(){
	int n;
	cout<<"Nhap so luong danh sach n = "; cin>>n;
	cin.ignore();
	SQ *a=new SQ[n];
	nhap(a,n);
	xuat(a,n);
	tk(a,n);
	sx(a,n);
	delete[] a;
}