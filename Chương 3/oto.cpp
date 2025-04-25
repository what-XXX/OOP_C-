#include<iostream>
#include<cstring>
using namespace std;

class OTO{
	private:
		char ma[30], hang[30];
		int so_ghe;
		float gia;
	public:
		//ham khoi tao
		OTO(const char* ma="", const char* hang="",int so_ghe=0, float gia=0){
			strcpy(this->ma,ma);
			strcpy(this->hang,hang);
			this->so_ghe=so_ghe;
			this->gia=gia;
		}
		//ham huy
		~OTO(){}
		//toan tu nhap
		friend istream &operator>>(istream &inp, OTO &a){
			cout<<"Nhap ma hang: "; inp.getline(a.ma,30);
			cout<<"Nhap hang san xuat: "; inp.getline(a.hang,30);
			cout<<"Nhap so ghe: ";inp>>a.so_ghe;
			cout<<"Nhap gia chua thue: ";inp>>a.gia;
			inp.ignore();
			return inp;
		}
		//ham tinh gia sau thue
		float tinhThue() const{
			return gia+gia*0.12;
		}
		//toan tu xuat
		friend ostream &operator<<(ostream &out, OTO &a){
			out<<"Ma hang: "<<a.ma<<endl;
			out<<"Ten hang san xuat: "<<a.hang<<endl;
			out<<"So ghe: "<<a.so_ghe<<endl;
			out<<"Gia chua thue: "<<a.gia<<endl;
			out<<"Gia sau thue: "<<a.tinhThue()<<endl;
			return out;
		}
		//toan tu >
		bool operator > (int x){
			return this->so_ghe>x;
		}
		//toan tu <
		bool operator < (OTO &a){
			return this->gia<a.gia;
		}
};
//nhap danh sach
void nhap(OTO a[], int n){
	for(int i=0; i<n;i++){
		cout<<"Danh sach oto thu "<<i+1<<":\n";
		cin>>a[i];
	}
}
//xuat danh sach
void xuat(OTO a[], int n){
	for(int i=0; i<n;i++){
		cout<<"Danh sach oto thu "<<i+1<<":\n";
		cout<<a[i];
	}
}
//ds oto tren 29 ghe
void tk(OTO a[], int n){
	bool check=false;
	for(int i=0; i<n;i++){
		if(a[i]>29){
			cout<<"Danh sach oto co tren 29 ghe:\n";
			cout<<a[i];
			check=true;
			break;
		}
	}
	if(!check) {
		cout<<"Khong co oto nao co so ghe tren 29\n";
	}
}
//sap xep giam dam
void sx(OTO a[], int n){
	for(int i=0; i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]<a[j]){
				OTO tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
		}
	}
	cout<<"Danh sach sau khi da sap xep: \n";
	for(int i=0; i<n;i++){
		cout<<a[i];
	}
}
int main()
{
	int n;
	do{
		cout<<"Nhao so danh sach oto n = ";
		cin>>n;
		cin.ignore();
	}while(n<=0);
	OTO *a=new OTO[n];
	nhap(a,n);
	xuat(a,n);
	tk(a,n);
	sx(a,n);
	delete[] a;
}