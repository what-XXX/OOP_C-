#include<iostream>
using namespace std;

class NhanVien{
	public:
		//ham ao
		virtual void nhap(){
		}
		//ham thuan ao
		virtual void xuat()=0;
		virtual float luong()=0;
		virtual char *check()=0;
};
class NVSX:public NhanVien{
	int sosp;
	public:
		void nhap(){
			cout<<"\n Nhap so san pham: "; cin>>sosp;
		}
		float luong(){
			return sosp*50;
		}
		void xuat(){
			cout<<"\n So san pham: "<<sosp;
			cout<<"\n Luong: "<<luong();
		}
		virtual char *check(){
			return "sx";
		}
};
class NVKD:public NhanVien{
	int dt;
	public:
		void nhap(){
			cout<<"\n Nhap doanh thu: "; cin>>dt;
		}
		float luong(){
			return dt*100;
		}
		void xuat(){
			cout<<"\n Doanh thu: "<<dt;
			cout<<"\n Luong: "<<luong();
		}
		virtual char *check(){
			return "kd";
		}
};
class NVBH:public NhanVien{
	int sl;
	public:
		void nhap(){
			cout<<"Nhap so luong hang hoa da ban: "; cin>>sl;
		}
		float luong(){
			return sl*15;
		}
		void xuat(){
			cout<<"\n So luong hang da ban: "<<sl;
			cout<<"\n Luong: "<<luong();
		}
		virtual char *check(){
			return "bh";
		}
};
class QuanLy{
	public:
		NhanVien *nv[100]; // tao dah sach cac con tro lop Nhan vien
		int n;

void nhap(){
	int lc, i=0; float s=0,n;
	while(1){
		cout<<"\n NhanvienSX /NhanVienKD /NhanVienBH/ Thoat (1,2,3,4):";
		cin>>lc;
		if(lc==4) break;
		if(lc==1) nv[i]=new NVSX();
		if(lc==2) nv[i]=new NVKD();
		if(lc==3) nv[i]=new NVBH();
		 nv[i]->nhap();// goi ham nhap de thuc hien cong viec
		 s+=nv[i]->luong();
		 i++;
		 n=i;//so luong nhan vien
	}
	cout<<"\ Tong luong: "<<s<<endl;
}
void xuat(){
	for(int i=0; i<n;i++){
		cout<<"\n Thong tin san pham thu "<<i<<":";
		nv[i]->xuat();
	}
}
//in ra danh sach nhan vien kinh doanh
void nvKD(){
	cout<<"Danh sach nhan vien kinh doanh: "<<endl;
	for(int i=0; i<n;i++){
		if(strcmp(nv[i]->check(),"kd")==0){
			nv[i]->xuat();
			cout<<endl;
		}
	}
} 
};
int main()
{
	QuanLy x;
	x.nhap();
	x.nvKD();
}