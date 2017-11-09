// vi du ve struct

#include<stdio.h>
#include<conio.h>

struct Date {
	unsigned ngay;
	unsigned thang;
	unsigned nam;
};

struct thoitiet  {
	struct Date thoigian;
	char diadiem[35];
	float luongmua;
	int nhietdo;
};

int main()  {
	struct thoitiet baocao[1000]; //toi da 1000 dia diem 
	struct thoitiet thoitietngay;  //thoi tiet ngay: cua 1 dia diem
	int n=0,i,nhietdomax, vitri; //vitri laf vij tris ngayf cos nhieetj ddooj cao nhaats , n la so dia diem nhaapj vaof
	float luongmuatb; //tong luong mua trung binh trong ngay cua tat ca cac khu vuc coongj laij
	
	printf("nhap du lieu, nhap ngay = 0 de dung lai: \n");
	do  {
		int temp; float temp2; //cac bien trung gian dungf ddeer nhaapj dwx lieeuj cho cacs bieens caaus trucs
		printf("\nNgay: "); scanf("%d",&temp); thoitietngay.thoigian.ngay = temp;
		
		if(temp!=0)  {   //neu ngay != 0
			printf("Thang: "); scanf("%d",&temp); thoitietngay.thoigian.thang = temp;
			if(temp!=0)  {   //neu thang != 0
				printf("Nam: "); scanf("%d",&temp); thoitietngay.thoigian.nam = temp;
				if(temp!=0)  {   //neu nam != 0
					printf("Dia diem: "); fflush(stdin); gets(thoitietngay.diadiem);
				    printf("Nhiet do: "); scanf("%d",&temp); thoitietngay.nhietdo = temp;
			    	printf("Luong mua: "); scanf("%f",&temp2); thoitietngay.luongmua = temp2;
			    	printf("\n");
			    	n++;
			    	baocao[n] = thoitietngay;  //neu nhap 7 dia diem thi n twf 1-7, ko phair twf 0-6
				}
			} 
		}
	} while(thoitietngay.thoigian.ngay!=0);
	
	//////////tim nhiet do cao nhat va luong mua trung binh/////////////
	nhietdomax = -128;
	luongmuatb = 0;
	for(i=1; i<=n; i++)  {
		if(nhietdomax < baocao[i].nhietdo)  {
			nhietdomax = baocao[i].nhietdo;
			vitri = i; //vi tri dia diem co nhiet do cao nhat
		}
		luongmuatb+= baocao[i].luongmua;
	}
	
	////////////in kq////////////
	printf("\nNhiet do cao nhat quan sat duoc la: %d, tai vi tri %s, vao ngay %d thang %d nam %d",nhietdomax,baocao[vitri].diadiem,baocao[vitri].thoigian.ngay,baocao[vitri].thoigian.thang,baocao[vitri].thoigian.nam);  
	printf("\ntong luong mua trung  cua %d khu vuc la %f",n,(luongmuatb/n));
	return 0;
}
