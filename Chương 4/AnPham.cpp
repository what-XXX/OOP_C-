#include<iostream>
#include<cstring>
using namespace std;

class AnPham{
	private:
		char ten[30];
		float gia;
	public:
		AnPham(const char* ten="", float gia=0.0){
			this->gia=gia;
			strcpy(this->ten,ten);
		}
		friend istream &operator>>(istream &is, AnPham &a){
			cout<<"Nhap ten: "; is.getline(a.ten,30);
			cout<<"Nhap gia thanh: "; is>>a.gia;
			is.ignore();
			return is;
		}
		friend ostream &operator<<(ostream &os, AnPham &a){
			os<<"Ten: "<<a.ten<<endl;
			os<<"Gia thanh: "<<a.gia<<endl;
			return os;
		}
		char* getName(){
			return ten;
		}
};
class Sach:public AnPham{
	private:
		int soTrang;
	public:
		Sach(const char* ten="", float gia=0.0,int soTrang=0):AnPham(ten,gia){
			this->soTrang=soTrang;
		}
		friend istream &operator>>(istream &is, Sach &a){
			is>>(AnPham&)a;
			cout<<"Nhap so trang sach: "; is>>a.soTrang;
			is.ignore();
			return is;
		}
		friend ostream &operator<<(ostream &os, Sach &a){
			os<<(AnPham&)a;
			os<<"So trang sach: "<<a.soTrang;
			return os;
		}
		bool operator > (int x){
			return this->soTrang>x;
		}
};
class DiaCD:public AnPham{
	private:
		int soPhut;
	public:
		DiaCD(const char* ten="", float gia=0.0,int soPhut=0):AnPham(ten,gia){
			this->soPhut=soPhut;
		}
		friend istream &operator>>(istream &is, DiaCD &a){
			is>>(AnPham&)a;
			cout<<"Nhap so phut: "; is>>a.soPhut;
			is.ignore();
			return is;
		}
		friend ostream &operator<<(ostream &os, DiaCD &a){
			os<<(AnPham&)a;
			os<<"So phut vua nhap: "<<a.soPhut<<endl;
			return os;
		}
		bool operator ==(char *x){
			return this->getName()==x;
		}
};
void nhap1(Sach a[], int n){
	for(int i=0; i<n;i++){
		cout<<"Nhap thong tin cuon sach thu "<<i+1<<":\n";
		cin>>a[i];
	}
}
void xuat1(Sach a[], int n){
	for(int i=0; i<n;i++){
		cout<<"Thong tin cuon sach thu "<<i+1<<":\n";
		cout<<a[i];
	}
}
void nhap2(DiaCD a[], int n){
	for(int i=0; i<n;i++){
		cout<<"Nhap thong tin dia CD thu "<<i+1<<":\n";
		cin>>a[i];
	}
}
void xuat2(DiaCD a[], int n){
	for(int i=0; i<n;i++){
		cout<<"Thong tin dia CD thu "<<i+1<<":\n";
		cout<<a[i];
	}
}
void tk1(Sach a[], int n){
	bool check=false;
	for(int i=0; i<n;i++){
		if(a[i]>500){
			cout<<"Sach co so trang lon hon 500:\n";
			cout<<a[i];
			check=true;
			break;
		}
	}
	if(!check) cout<<"Khong co cuon sach nao co so trang lon hon 500";
}
void tk2(DiaCD a[], int n){
	char x[30]; 
	cout<<"Nhap ten dia CD can tim: "; cin>>x;
	cin.ignore();
	bool check=false;
	for(int i=0; i<n;i++){
		if(a[i]==x){
			cout<<"Thong tin dia CD co ten "<<x<<":\n";
			cout<<a[i];
			check=true;
			break;
		}
	}
	if(!check) cout<<"Khong co dia CD nao can tim\n";
}
int main()
{
	int n,m; 
	cout<<"Nhap so luong sach: "; cin>>n;
	cin.ignore();
	Sach *a=new Sach[n];
	nhap1(a,n);
	xuat1(a,n);
	tk1(a,n);
	cout<<endl;
	delete[] a;
	cout<<"Nhap so luong dia CD: "; cin>>m;
	cin.ignore();
	DiaCD *b=new DiaCD[m];
	nhap2(b,m);
	xuat2(b,m);
	tk2(b,m);
	delete[] b;
}