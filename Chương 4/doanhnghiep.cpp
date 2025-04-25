#include<iostream>
#include<cstring>
using namespace std;

class DN{
	private:
		char ms[30],ten[30];
		float soVon;
	public:
		DN(const char* ms="", const char* ten="",float soVon=0.0){
			strcpy(this->ms,ms);
			strcpy(this->ten,ten);
			this->soVon=soVon;
		}
		~DN(){}
		friend istream &operator>>(istream &is, DN &a){
			cout<<"Nhap ma so: "; is.getline(a.ms,30);
			cout<<"Nhap ten doanh nghiep: ";is.getline(a.ten,30);
			cout<<"Nhap so von dau tu: ";is>>a.soVon;
			is.ignore();
			return is;
		}
		friend ostream &operator<<(ostream &os, DN &a){
			os<<"Ma so: "<<a.ms<<endl;
			os<<"Ten doanh nghiep: "<<a.ten<<endl;
			os<<"So von dau tu: "<<a.soVon<<endl;
			return os;
		}
		float getSovon(){
			return soVon;
		}
};
class DNSX:public DN{
	private:
		float dt;
		char dc[30];
	public:
		DNSX(const char* dc="", float dt=0.0,const char* ms="", const char* ten="",float soVon=0.0):DN(ms,ten,soVon){
			this->dt=dt;
			strcpy(this->dc,dc);
		}
		~DNSX(){}
		friend istream &operator >>(istream &is, DNSX &a){
			is>>(DN&)a;
			cout<<"Nhap dia chi: "; is.getline(a.dc,30);
			cout<<"Nhap doanh thu: "; is>>a.dt;
			is.ignore();
			return is;
		}
		friend ostream &operator <<(ostream &os, DNSX &a){
			os<<(DN&)a;
			os<<"Doanh thu: "<<a.dt<<endl;
			os<<"Dia chi: "<<a.dc<<endl;
			os<<"Thue: "<<a.tinhThue()<<endl;
			return os;
		}
		float tinhThue(){
			if(getSovon()>500) return 0.1*dt;
			else return 0.05*dt;
		}
		bool operator <(DNSX &a){
			return this->getSovon()<a.getSovon();
		}
		bool operator ==(char *x){
			return this->dc==x;
		}
};
void nhap1(DN a[], int n){
	for(int i=0; i<n;i++){
		cout<<"Nhap thong tin doanh nghiep thu "<<i+1<<":\n";
		cin>>a[i];
	}
}
void xuat1(DN a[], int n){
	for(int i=0; i<n;i++){
		cout<<"Thong tin doanh nghiep thu "<<i+1<<":\n";
		cout<<a[i];
	}
}
void nhap2(DNSX a[], int n){
	for(int i=0; i<n;i++){
		cout<<"Nhap thong tin doanh nghiep san xuat thu "<<i+1<<":\n";
		cin>>a[i];
	}
}
void xuat2(DNSX a[], int n){
	for(int i=0; i<n;i++){
		cout<<"Thong tin doanh nghiep san xuat thu "<<i+1<<":\n";
		cout<<a[i];
	}
}
void tk1(DNSX a[], int n){
	bool check=false;
	cout<<"Danh sach nhung doanh nghiep san xuat co dia chi Ha Noi: \n";
	for(int i=0; i<n;i++){
		if(a[i]=="Ha Noi"){
			cout<<a[i];
			check=true;
			break;
		}
	}
	if(!check) cout<<"Khong co doanh nghiep san xuat nao co dia chi o Ha Noi\n";
}
void sx(DNSX a[], int n){
	for(int i=0; i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]<a[j]){
				DNSX tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
		}
	}
	cout<<"Danh sach doanh nghiep san xuat sau khi sap xep:\n";
	xuat2(a,n);
}
void chen(DNSX a[], int &n){
	int k; 
	cout<<"Nhap vi tri danh sach can chen k = "; cin>>k;
	cin.ignore();
	cout<<"Nhap danh sach can chen vao: \n";
	cin>>a[k];
	for(int i=n;i>=k;i--){
		a[i]=a[i-1];
	}
	n++;
	cout<<"Danh sach doanh nghiep san xuat sau khi chen la: \n";
	xuat2(a,n);
}
int main(){
	int n,m;
	cout<<"Nhap so luong doanh nghiep: "; cin>>n;
	cin.ignore();
	DN *a=new DN[n];
	nhap1(a,n);
	xuat1(a,n);
	delete[] a;
	cout<<"Nhap so luong doanh nghiep san xuat: "; cin>>m;
	cin.ignore();
	DNSX* b=new DNSX[m+1];
	nhap2(b,m);
	xuat2(b,m);
	tk1(b,m);
	sx(b,m);
	chen(b,m);
	delete[] b;
}