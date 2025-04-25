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
		friend istream &operator>>(istream &is, Nguoi &a){
			cout<<"Nhap ho ten: "; is.getline(a.ht,30);
			cout<<"Nhap nam sinh: "; is>>a.ns;
			is.ignore();
			return is;
		}
		friend ostream &operator<<(ostream &os, Nguoi &a){
			os<<"Ho ten: "<<a.ht<<endl;
			os<<"Nam sinh: "<<a.ns<<endl;
			return os;
		}
};
class ThiSinh:public Nguoi{
	private:
		int sbd;
		float toan, ly, hoa;
	public:
		ThiSinh(int sbd=0, float toan=0.0, float ly=0.0, float hoa=0.0,const char* ht="", int ns=0):Nguoi(ht,ns){
			this->sbd=sbd;
			this->toan=toan;
			this->ly=ly;
			this->hoa=hoa;
		}
		friend istream &operator>>(istream &is, ThiSinh &a){
			is>>(Nguoi&)a;
			cout<<"Nhap so bao danh: "; is>>a.sbd;
			cout<<"Nhap diem toan: "; is>>a.toan;
			cout<<"Nhap diem ly: "; is>>a.ly;
			cout<<"Nhap diem hoa: "; is>>a.hoa;
			is.ignore();
			return is;
		}
		friend ostream &operator<<(ostream &os, ThiSinh &a){
			os<<(Nguoi&)a;
			os<<"So bao danh: "<<a.sbd<<endl;
			os<<"Diem toan: "<<a.toan<<endl;
			os<<"Diem ly: "<<a.ly<<endl;
			os<<"Diem hoa: "<<a.hoa<<endl;
			return os;
		}
		float getToan(){
			return toan;
		}
		float getLy(){
			return ly;
		}
		float getHoa(){
			return hoa;
		} 
		int getSbd(){
			return sbd;
		}
		bool operator ==(int x){
			return this->sbd==x;
		}
};
void nhap(ThiSinh a[], int n){
	for(int i=0; i<n;i++){
		cout<<"Nhap thong tin thi sinh thu "<<i+1<<":\n";
		cin>>a[i];
	}
}
void xuat(ThiSinh a[] , int n){
	for(int i=0; i<n;i++){
		cout<<"Thong tin thi sinh thu "<<i+1<<":\n";
		cout<<a[i];
	}
}
void tk1(ThiSinh a[],int n){
	bool check=false;
	cout<<"Danh sach thi sinh co tong diem 3 mon tang dan:\n";
	for(int i=0; i<n;i++){
		if(a[i].getToan()<a[i].getLy()&&a[i].getLy()<a[i].getHoa()){
			check=true;
			cout<<a[i];
			break;
		}
	}
	if(!check) {
		cout<<"Khong co thi sinh nao co tong diem 3 mon tang dan\n";
	}
}
void tk2(ThiSinh a[], int n){
	int x; 
	cout<<"Nhap so bao danh can tim: "; cin>>x;
	bool check=false;
	for(int i=0; i<n;i++){
		if(a[i].getSbd()==x){
			cout<<"Thong tin thi sinh can tim: \n";
			cout<<a[i];
			check=true;
		}
	}
	if(!check){
		cout<<"Khong co thong tin cua thi sinh can tim\n";
	}
}
void dem(ThiSinh a[], int n){
	int cnt =0;
	for(int i=0; i<n;i++){
		if(a[i].getToan()>=5.0&&a[i].getLy()>=5.0&&a[i].getHoa()>=5.0){
			++cnt;
		}
	}
	cout<<"So luong thi sinh dat yeu cau: "<<cnt;
}
int main(){
	int n;
	cout<<"Nhap so luong thi sinh: "; cin>>n;
	cin.ignore();
	ThiSinh *a=new ThiSinh[n];
	nhap(a,n);
	tk1(a,n);
	cout<<endl;
	tk2(a,n);
	cout<<endl;
	dem(a,n);
	delete[] a;
}