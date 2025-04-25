#include<iostream>
#include<cstring>
using namespace std;

class Nguoi{
	private:
		char ht[30];
		int ns;
	public:
		Nguoi(const char* ht="", int ns=0){
			strcpy(this->ht,ht);
			this->ns=ns;
		}
		~Nguoi(){}
		friend istream &operator >>(istream &is, Nguoi &a){
			cout<<"Nhap ho ten: "; is.getline(a.ht,30);
			cout<<"Nhap nam sinh: ";is>>a.ns;
			is.ignore();
			return is;
		}
		friend ostream &operator <<(ostream &os, Nguoi &a){
			os<<"Ho ten: "<<a.ht<<endl;
			os<<"Nam sinh: "<<a.ns<<endl;
			return os;
		}
};
class SV{
	private:
		char hk[10];
		float diem;
	public:
		SV(const char* hk="", float diem=0.0){
			strcpy(this->hk,hk);
			this->diem=diem;
		}
		~SV(){}
		friend istream &operator>>(istream &is, SV &a){
			cout<<"Nhap hanh kiem: "; is.getline(a.hk,10);
			cout<<"Nhap diem: "; is>>a.diem;
			is.ignore();
			return is;
		}
		friend ostream &operator<<(ostream &os, SV &a){
			os<<"Hanh kiem: "<<a.hk<<endl;
			os<<"Diem: "<<a.diem<<endl;
			return os;
		}
		char* getHk() {
			return hk;
		}
		float getDiem(){
			return diem;
		}
		bool operator >(SV &a){
			return this->diem>a.diem;
		}
};
class SVTC:public Nguoi, public SV{
	private:
		float hp;
	public:
		SVTC(const char* ht="", int ns=0,const char* hk="", float diem=0.0,float hp=0.0):Nguoi(ht,ns),SV(hk,diem){
			this->hp=hp;
		}
		friend istream &operator>>(istream &is, SVTC &a){
			is>>(Nguoi&)a;
			is>>(SV&)a;
			cout<<"Nhap hoc phi: "; is>>a.hp;
			is.ignore();
			return is;
		}
		friend ostream &operator <<(ostream &os, SVTC &a){
			os<<(Nguoi&)a;
			os<<(SV&)a;
			os<<"Hoc phi: "<<a.hp<<endl;
			return os;
		}
		float tinhHB(){
			if((strcmp(getHk(),"Tot")==0)&&getDiem()>=9.0){
				return 5000000;
			}
			else if((strcmp(getHk(),"Tot")==0||strcmp(getHk(),"Kha")==0)&&getDiem()>=8.0){
				return 3000000;
			}
			else if(strcmp(getHk(),"Kha")==0&&getDiem()>=7.0){
				return 2000000;
			}
			else{
				return 0;
			}
		}
		bool operator >(SVTC &a){
			return SV::operator >(a);
		}
};
void nhap(SVTC a[], int n){
	for(int i=0; i<n;i++){
		cout<<"Nhap danh sach sinh vien tai chuc thu "<<i+1<<":\n";
		cin>>a[i];
	}
}
void xuat(SVTC a[], int n){
	for(int i=0; i<n;i++){
		cout<<"Danh sach sinh vien tai chuc thu "<<i+1<<":\n";
		cout<<a[i];
	}
}
void tk(SVTC a[], int n){
	bool check=false;
	cout<<"Danh sach sinh vien dat hoc bong: \n";
	for(int i=0; i<n;i++){
		if(a[i].tinhHB()>0){
			cout<<a[i];
			check=true;
			break;
		}
	}
	if(!check) cout<<"Khong co sinh vien nao dat hoc bong\n";
}
void sx(SVTC a[], int n){
	for(int i=0; i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]>a[j]){
				SVTC tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
		}
	}
	cout<<"Danh sach sinh vien tai chuc sau khi sap xep: \n";
	xuat(a,n);
}
int main()
{
	int n;
	cout<<"Nhap so luong danh sach n ="; cin>>n;
	cin.ignore() ;
	SVTC *a=new SVTC[n];
	nhap(a,n);
	xuat(a,n);
	tk(a,n);
	sx(a,n);
	delete[] a;
}