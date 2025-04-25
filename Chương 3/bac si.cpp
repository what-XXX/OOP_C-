#include<iostream>
#include<cstring>
using namespace std;

class BACSI{
	private:
		char ma[30],ht[30],ck[20];
		int so_nam;
		float luong;
	public:
		//ham khoi tao
		BACSI(const char* ma="", const char* ht="", const char* ck="", int so_nam=0,float luong=0.0){
			strcpy(this->ma,ma);
			strcpy(this->ht,ht);
			strcpy(this->ck,ck);
			this->so_nam=so_nam;
			this->luong=luong;
		}
		//ham huy
		~BACSI(){}
		//toan tu nhap
		friend istream &operator>>(istream &is, BACSI &a){
			cout<<"Nhap ma: "; is.getline(a.ma,30);
			cout<<"Nhap ho ten bac si: "; is.getline(a.ht,30);
			cout<<"Nhap chuyen khoa: "; is.getline(a.ck,20);
			cout<<"Nhap so nam kinh nghiem: ";is>>a.so_nam;
			cout<<"Nhap luong co ban: ";is>>a.luong;
			is.ignore();
			return is;
		}
		//ham tinh luong thuc linh
		float tinhLuong() const{
			return luong+luong*0.1;
		}
		//toan tu xuat
		friend ostream &operator<<(ostream &os, BACSI &a){
			os<<"Ma: "<<a.ma<<endl;
			os<<"Ho ten bac si: "<<a.ht<<endl;
			os<<"Chuyen khoa: "<<a.ck<<endl;
			os<<"So nam kinh nghiem: "<<a.so_nam<<endl;
			os<<"Luong co ban: "<<a.luong<<endl;
			return os;
		}
		//toan tu >
		bool operator > (int x){
			return this->so_nam>x;
		}
		bool operator < (BACSI &a){
			return this->luong < a.luong;
		}
};
//nhap ds
void nhap(BACSI a[], int n){
	for(int i=0; i<n;i++){
		cout<<"Nhap thong tin bac si thu "<<i+1<<":\n";
		cin>>a[i];
	}
}
//xuat ds
void xuat(BACSI a[], int n){
	for(int i=0; i<n;i++){
		cout<<"Thong tin bac si thu "<<i+1<<":\n";
		cout<<a[i];
	}
}
//ds bac si co tren 10 nam kinh nghiem
void tk(BACSI a[], int n){
	bool check=false;
	for(int i=0; i<n;i++){
		if(a[i]>10){
			cout<<"Danh sach bac si co tren 10 nam kinh nghiem: \n";
			cout<<a[i];
			check=true;
			break;
		}
	}
	if(!check){
		cout<<"Khong co bac si nao co tren 10 nam kinh nghiem\n";
	}
}
//sap xep theo thu tu giam dan
void sx(BACSI a[], int n){
	for(int i=0; i<n-1;i++){
		for(int j=i+1; j<n;j++){
			if(a[i]<a[j]){
				BACSI tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
		}
	}
	cout<<"Danh sach sau khi sap xep: \n";
	xuat(a,n);
}
int main()
{
	int n;
	do{
		cout<<"Nhap so luong danh sach bac si n = "; 
		cin>>n;
		cin.ignore();
	}while(n<=0);
	BACSI *a=new BACSI[n];
	nhap(a,n);
	xuat(a,n);
	tk(a,n);
	sx(a,n);
	delete[] a;
}