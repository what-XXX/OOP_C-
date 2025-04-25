#include<iostream>
using namespace std;

class NhanVien // lop truu tuong
{
	public:
		//ham ao
		virtual void nhap(){
		}
		//ham thuan ao
		virtual void xuat() = 0;
		virtual float luong()=0;
		virtual char *check()=0;//phan biet cac doi tuong o cac lop khac nhau
};
class NVSX: public NhanVien{
	int sosp;
	public:
		void nhap(){
			cout<<"Nhap so san pham: "; cin>>sosp;
		}
		float luong(){
			return sosp*50;
		}
		void xuat(){
			cout<<"So san pham: \n"<<sosp<<endl;
			cout<<"Luong: "<<luong()<<endl;
		}
		virtual char *check(){
			return "sx";
		}
};
class NVKD:public NhanVien{
	int dt;
	public:
		void nhap(){
			cout<<"Nhap doanh thu: "; cin>>dt;
		}
		float luong(){
			return dt*100;
		}
		void xuat(){
			cout<<"Doanh thu: "<<dt<<endl;
			cout<<"Luong: "<<luong()<<endl;
		}
		virtual char *check(){
			return "kd";
		}
};
int main()
{
	NhanVien *nv[100];
	int lc,i=0;
	float s=0,n;
	while(1)//lap de nhap danh sach
	{
		cout<<"\n*NhanVienSX / NhanVienKD/ Thoat (1,2,3):";
		cin>>lc;
		if(lc==3) break;
		if(lc==2) nv[i]=new NVKD();//tao ra doi tuong NVKD
		if(lc==1) nv[i]=new NVSX();// tao ra doi tuong NVSX
		nv[i]->nhap();//goi ham nhap de thuc hien cong viec
		s+=nv[i]->luong();
		i++;
		n=i;//so luong nhan vien
	}
	cout<<"Tong luong: "<<s<<endl;
	for(int i=0; i<n;i++){
		nv[i]->xuat();
		cout<<endl;
	}
	cout<<"Danh sach nhan vien KD"<<endl;
	for(int i=0; i<=n;i++){
		if(strcmp(nv[i]->check(),"kd")==0){
			nv[i]->xuat();
			cout<<endl;
		}
	}
}