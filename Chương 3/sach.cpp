#include<iostream>
#include<cstring>
using namespace std;

class SACH{
	private:
		char ma[30],ten[30],tgia[30],nxb[20];
		float gia;
	public:
		//ham tao
		SACH(const char* ma="", const char* ten="", const char* tgia="", const char* nxb=""){
			strcpy(this->ma,ma);
			strcpy(this->ten,ten);
			strcpy(this->tgia,tgia);
			strcpy(this->nxb,nxb);
			this->gia=gia;
		}
		//ham huy
		~SACH(){}
		//toan tu nhap
		friend istream &operator>>(istream &is, SACH &a){
			cout<<"Nhap ma sach: "; is.getline(a.ma,30);
			cout<<"Nhap ho ten tac gia: "; is.getline(a.tgia,30);
			cout<<"Nhap ten sach: "; is.getline(a.ten,30);
			cout<<"Nhap ten nha xuat ban: ";is.getline(a.nxb,20);
			cout<<"Nhap gia chua thue: ";is>>a.gia;
			is.ignore();
			return is;
		}
		//ham tinh gia sau thue
		float tinhThue() const{
			return gia+gia*0.08;
		}
		//toan tu xuat 
		friend ostream &operator<<(ostream &os, SACH &a){
			os<<"Ma sach: "<<a.ma<<endl;
			os<<"Ho ten tac gia: "<<a.tgia<<endl;
			os<<"Ten sach: "<<a.ten<<endl;
			os<<"Ten nha xuat ban: "<<a.nxb<<endl;
			os<<"Gia chua thue: "<<a.gia<<endl;
			os<<"Gia sau khi tinh thue: "<<a.tinhThue()<<endl;
			return os;
		}		
		//toan tu >
		bool operator >(float x){
			return this->gia>x;
		}
		//toan tu <
		bool operator <(SACH &a){
			return this->gia<a.gia;
		}
		
};
//nhap ds
void nhap(SACH a[], int n){
	for(int i=0; i<n;i++){
		cout<<"Nhap thong tin sach thu "<<i+1<<":\n";
		cin>>a[i];
	}
}
//xuat ds
void xuat(SACH a[], int n){
	for(int i=0; i<n;i++){
		cout<<"Thong tin cuon sach thu "<<i+1<<":\n";
		cout<<a[i];
	}
}
//ds sach co gia chua thue >100000
void tk(SACH a[], int n){
	bool check=false;
	for(int i=0; i<n;i++){
		if(a[i]>100000){
			cout<<"Thong tin cuon sach co gia chua thue lon hon 100000:\n";
			cout<<a[i];
		}
	}
	if(!check) cout<<"Khong co cuon sach nao co gia chua thue lon hon 100000\n";
}
//sap xep ds theo tt giam dan
void sx(SACH a[], int n){
	for(int i=0; i<n-1;i++){
		for(int j=i+1; j<n;j++){
			if(a[i]<a[j]){
				SACH tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
		}
	}
	cout<<"Danh sach sau khi sap xep:\n";
	xuat(a,n);
}
int main(){
	int n;
	cout<<"Nhap so luong danh sach n = ";
	cin>>n;
	cin.ignore();
	SACH *a=new SACH[n];
	nhap(a,n);
	xuat(a,n);
	tk(a,n);
	sx(a,n);
	delete[] a;
}