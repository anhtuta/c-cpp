//quan ly diem thi vao truong DHBKHN cua cac thi sinh, in ra cac thi sinh co tong diem >=18

#include<iostream>
#include<conio.h>
#include<stdio.h>

using namespace std;

class thisinh  {
	char ten[25]; //ten co ddooj daif toois dda laf 24 ki tuwj
	int t,l,h; //ddieemr 3 moon toan,li,hoa
	public: 
	   void nhapdl();
	   void inkq()  { printf("%24s%6d%6d%6d%6d",ten,t,l,h,tong()); }
	   int tong()  { return t+l+h;  }
};

void thisinh::nhapdl()  {
	cout<<"\nTen: ";  gets(ten);
	cout<<"\nDiem Toan: ";  cin>>t;
	cout<<"\nDiem Li: ";  cin>>l;
	cout<<"\nDiem Hoa: ";  cin>>h;
}

int main()  {
	int n;
	cout<<"\nNhap vao so thi sinh: "; cin>>n;
	thisinh *dsts = new thisinh[n];
	for(int i=0; i<n; i++)  {
		cout<<"\nNhap du lieu cho thi sinh thu "<<(i+1);
		dsts[i].nhapdl();
	}
	
	//in danh sach
	cout<<"\nCac thi sinh trung tuyen la: ";
	printf("%24s%6s%6s%6s%6s","Ten","Toan","Li","Hoa","Tong");
	for(int i=0; i<n; i++)  {
		if(dsts[i].tong()>=18) dsts[i].inkq();
	}
	
	delete dsts;
}
