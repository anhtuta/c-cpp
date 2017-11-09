//quan li nhan vien cua 1 van phong: in danh sach nhan vien va nhan vien co luong cao va thap nhat

#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>


using namespace std;
using std::string;

typedef struct {
	int d,m,y;  //day, month, year
} Date;

typedef struct Nvien {
	char name[30];
	Date sinhnhat;
	char chucvu[30];
	float luong;
} Employee;

void display(Employee nvien); //ham hien thi thong tin 1 nhan vien
void nhap_dsnv(Employee *dsnv, int n);  //nhap danh sach nhan vien, n = soos luwowngj nhaan vieen nhaapj vaof
Employee tim_luong_max(Employee *dsnv, int n);  //ham tim nhan vien co luong cao nhat, ket qua tra ve laf 1 bien cos kieeur duwx lieeuj Employee
Employee tim_luong_min(Employee *dsnv, int n);  //ham tim nhan vien co luong thap nhat

int main()  {
	int n,i;
	Employee *ds;
	Employee temp;
	cout<<"nhap vao so nhan vien: "; cin>>n;
	
	nhap_dsnv(ds,n);
	
	///////hien thi danh sach vua nhap/////
	cout<<"\nDanh sach nhan vien ban vua nhap la: ";
	for(i=0; i<n; i++)  {
		cout<<"\nNhan vien thu "<<i+1<<": ";
		display(ds[i]);
	}
	
	//////tim nhan vien luong max va min///////////
	temp = tim_luong_max(ds, n);
	cout<<"\nNhan vien co luong cao nhat la: ";
	display(temp);
	temp = tim_luong_min(ds, n);
	cout<<"\nNhan vien co luong thap nhat la: ";
	display(temp);
	
}

//dinh nghia cac ham
void display(Employee nvien)  {
	cout<<"\nHo va ten: "<<nvien.name;
	cout<<"\nNgay sinh: "<<nvien.sinhnhat.d<<"/"<<nvien.sinhnhat.m<<"/"<<nvien.sinhnhat.y;
	cout<<"\nChuc vu: "<<nvien.chucvu;
	cout<<"\nLuong: "<<nvien.luong<<endl;
}

void nhap_dsnv(Employee *dsnv, int n)  {
	dsnv = new Employee[n];  //cap phat dong cho mang dsnv
	char temp2[30];
	cout<<"\nNhap du lieu cho cac nhan vien: ";
	for(int i=0; i<n; i++)  {
		cout<<"\nNhap du lieu cho nhan vien thu "<<i+1<<": ";
		cout<<"\nHo va ten: "; cin>>temp2; fflush(stdin);
		strcpy(dsnv[i].name,temp2);
		cout<<"\nNgay sinh: "; 
		cout<<"\nNgay: "; cin>>dsnv[i].sinhnhat.d;
		cout<<"\nThang: "; cin>>dsnv[i].sinhnhat.m;
		cout<<"\nNam: "; cin>>dsnv[i].sinhnhat.y;
		cout<<"\nChuc vu: "; cin>>temp2; fflush(stdin);
		strcpy(dsnv[i].chucvu,temp2);
		cout<<"\nLuong: "; cin>>dsnv[i].luong;
	}
	return;
}

Employee tim_luong_max(Employee *dsnv, int n)  {
	int index = 0;
	float max = dsnv[0].luong;
	for(int i=1; i<n; i++)  {
		if(max < dsnv[i].luong) {
			max = dsnv[i].luong;
			index = i;
		}
	}
	return dsnv[index];
}

Employee tim_luong_min(Employee *dsnv, int n)  {
	int index = 0;
	float min = dsnv[0].luong;
	for(int i=1; i<n; i++)  {
		if((min > dsnv[i].luong)) {
			min = dsnv[i].luong;
			index = i;
		}
	}
	return dsnv[index];
}

